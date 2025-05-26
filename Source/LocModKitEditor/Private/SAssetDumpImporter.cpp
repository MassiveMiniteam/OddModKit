// Copyright Epic Games, Inc. All Rights Reserved.


#include "SAssetDumpImporter.h"
#include "Modules/ModuleManager.h"
#include "Widgets/SWindow.h"
#include "Layout/WidgetPath.h"
#include "SlateOptMacros.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SUniformGridPanel.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SButton.h"
#include "Styling/AppStyle.h"
#include "Interfaces/IMainFrameModule.h"

#define LOCTEXT_NAMESPACE "PackageReportDialog"

struct FCompareFPackageReportNodeByName
{
	FORCEINLINE bool operator()( TSharedPtr<FPackageReportNode> A, TSharedPtr<FPackageReportNode> B ) const
	{
		return A->NodeName < B->NodeName;
	}
};

FPackageReportNode::FPackageReportNode()
	: CheckedState(ECheckBoxState::Undetermined)
	, bShouldMigratePackage(nullptr)
	, bIsFolder(false)
	, Parent(nullptr)
{}

FPackageReportNode::FPackageReportNode(const FString& InNodeName, bool InIsFolder)
	: NodeName(InNodeName)
	, CheckedState(ECheckBoxState::Undetermined)
	, bShouldMigratePackage(nullptr)
	, bIsFolder(InIsFolder)
	, Parent(nullptr)
{}

void FPackageReportNode::AddPackage(const FString& PackageName, bool* bInShouldMigratePackage)
{
	TArray<FString> PathElements;
	PackageName.ParseIntoArray(PathElements, TEXT("/"), /*InCullEmpty=*/true);

	(void)AddPackage_Recursive(PathElements, bInShouldMigratePackage);
}

void FPackageReportNode::ExpandChildrenRecursively(const TSharedRef<PackageReportTree>& Treeview, bool bOnlyChecked)
{
	for ( auto ChildIt = Children.CreateConstIterator(); ChildIt; ++ChildIt )
	{
		Treeview->SetItemExpansion(*ChildIt, bOnlyChecked ? ((*ChildIt)->CheckedState != ECheckBoxState::Unchecked) : true);
		(*ChildIt)->ExpandChildrenRecursively(Treeview, bOnlyChecked);
	}
}

FPackageReportNode::FChildrenState FPackageReportNode::AddPackage_Recursive(TArray<FString>& PathElements, bool* bInShouldMigratePackage)
{
	FChildrenState ChildrenState;
	ChildrenState.bAnyChildIsChecked = false;
	ChildrenState.bAllChildrenAreChecked = true;

	if ( PathElements.Num() > 0 )
	{
		// Pop the bottom element
		FString ChildNodeName = PathElements[0];
		PathElements.RemoveAt(0);

		// Try to find a child which uses this folder name
		TSharedPtr<FPackageReportNode> Child;
		for ( auto ChildIt = Children.CreateConstIterator(); ChildIt; ++ChildIt )
		{
			if ( (*ChildIt)->NodeName == ChildNodeName )
			{
				Child = (*ChildIt);
				break;
			}
		}

		// If one was not found, create it
		if ( !Child.IsValid() )
		{
			const bool bIsAFolder = (PathElements.Num() > 0);
			int32 ChildIdx = Children.Add( MakeShareable(new FPackageReportNode(ChildNodeName, bIsAFolder)) );
			Child = Children[ChildIdx];
			Child.Get()->Parent = this;
			Children.Sort( FCompareFPackageReportNodeByName() );
		}

		if ( ensure(Child.IsValid()) )
		{
			FChildrenState ChildChildrenState = Child->AddPackage_Recursive(PathElements, bInShouldMigratePackage);
			ChildrenState.bAnyChildIsChecked |= ChildChildrenState.bAnyChildIsChecked;
			ChildrenState.bAllChildrenAreChecked &= ChildChildrenState.bAllChildrenAreChecked;
		}

		CheckedState = ChildrenState.bAllChildrenAreChecked ? ECheckBoxState::Checked : (ChildrenState.bAnyChildIsChecked ? ECheckBoxState::Undetermined : ECheckBoxState::Unchecked);
	}
	else
	{
		CheckedState = *bInShouldMigratePackage ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
		ChildrenState.bAnyChildIsChecked = ChildrenState.bAllChildrenAreChecked = CheckedState == ECheckBoxState::Checked;
		bShouldMigratePackage = bInShouldMigratePackage;
	}

	return ChildrenState;
}

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SAssetDumpImporter::Construct( const FArguments& InArgs, const FText& InReportMessage, TArray<ReportPackageData>& InPackageNames, const FOnReportConfirmed& InOnReportConfirmed )
{
	OnReportConfirmed = InOnReportConfirmed;
	FolderOpenBrush = FAppStyle::GetBrush("ContentBrowser.AssetTreeFolderOpen");
	FolderClosedBrush = FAppStyle::GetBrush("ContentBrowser.AssetTreeFolderClosed");
	PackageBrush = FAppStyle::GetBrush("ContentBrowser.ColumnViewAssetIcon");

	ConstructNodeTree(InPackageNames);
	
	ChildSlot
	[
		SNew(SBorder)
		.BorderImage( FAppStyle::GetBrush("Docking.Tab.ContentAreaBrush") )
		.Padding(FMargin(4, 8, 4, 4))
		[
			SNew(SVerticalBox)

			// Report Message
			+SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0, 4)
			[
			SNew(SVerticalBox)
			    
			+SVerticalBox::Slot()
			.AutoHeight()
			[
				SNew(STextBlock)
				.Text(InReportMessage)
				.TextStyle(FAppStyle::Get(), "PackageMigration.DialogTitle")
			]

			+SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0, 4)
			[
				SAssignNew(SearchBox, SEditableTextBox)
				.HintText(LOCTEXT("SearchHint", "Search packages..."))
				.OnTextChanged(this, &SAssetDumpImporter::OnSearchTextChanged)
			]
			]

			// Tree of packages in the report
			+SVerticalBox::Slot()
			.FillHeight(1.f)
			[
				SNew(SBorder)
				.BorderImage( FAppStyle::GetBrush("ToolPanel.GroupBorder") )
				[
					SAssignNew( ReportTreeView, PackageReportTree )
					.TreeItemsSource(&PackageReportRootNode.Children)
					.SelectionMode(ESelectionMode::Single)
					.OnGenerateRow( this, &SAssetDumpImporter::GenerateTreeRow )
					.OnGetChildren( this, &SAssetDumpImporter::GetChildrenForTree )
				]
			]

			// Ok/Cancel buttons
			+SVerticalBox::Slot()
			.AutoHeight()
			.HAlign(HAlign_Right)
			.Padding(0,4,0,0)
			[
				SNew(SUniformGridPanel)
				.SlotPadding(FAppStyle::GetMargin("StandardDialog.SlotPadding"))
				.MinDesiredSlotWidth(FAppStyle::GetFloat("StandardDialog.MinDesiredSlotWidth"))
				.MinDesiredSlotHeight(FAppStyle::GetFloat("StandardDialog.MinDesiredSlotHeight"))
				+SUniformGridPanel::Slot(0,0)
				[
					SNew(SButton)
					.HAlign(HAlign_Center)
					.ContentPadding( FAppStyle::GetMargin("StandardDialog.ContentPadding") )
					.OnClicked(this, &SAssetDumpImporter::OkClicked)
					.Text(LOCTEXT("OkButton", "OK"))
				]
				+SUniformGridPanel::Slot(1,0)
				[
					SNew(SButton)
					.HAlign(HAlign_Center)
					.ContentPadding( FAppStyle::GetMargin("StandardDialog.ContentPadding") )
					.OnClicked(this, &SAssetDumpImporter::CancelClicked)
					.Text(LOCTEXT("CancelButton", "Cancel"))
				]
			]
		]
	];

	if ( ensure(ReportTreeView.IsValid()) )
	{
		PackageReportRootNode.ExpandChildrenRecursively(ReportTreeView.ToSharedRef(), true);
	}
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SAssetDumpImporter::OnSearchTextChanged(const FText& InText)
{
	SearchText = InText;
	FilterTreeItems();
}

void SAssetDumpImporter::FilterTreeItems()
{
	const FString SearchString = SearchText.ToString();

	if (SearchString.IsEmpty())
	{
		// Restore full node list before filtering
		for (auto& Entry : OriginalNodes)
		{
			PackageReportRootNode.AddPackage(Entry.Entry.PackagePath + "/" + Entry.Entry.AssetName.ToString(), Entry.bShouldMigratePackage);
		}
		ReportTreeView->RebuildList();
		return;
	}

	TArray<FString> SearchParts;
	SearchString.ParseIntoArray(SearchParts, TEXT(" "));

	PackageReportRootNode.Children.Reset();

	// Apply filter
	for (auto& Entry : OriginalNodes)
	{
		bool bContainsAllParts = true;
		for (FString Part : SearchParts)
		{
			if (!(Entry.Entry.AssetName.ToString().Contains(Part) || Entry.Entry.PackagePath.Contains(Part)))
			{
				bContainsAllParts = false;
			}	
		}
		
		if (bContainsAllParts)
		{
			PackageReportRootNode.AddPackage(Entry.Entry.PackagePath + "/" + Entry.Entry.AssetName.ToString(), Entry.bShouldMigratePackage);
		}
	}

	// Update the tree view
	ReportTreeView->RebuildList();

	if (PackageReportRootNode.Children.Num() > 0)
	{
		TFunction<void(TSharedPtr<FPackageReportNode>)> Expand = [&](TSharedPtr<FPackageReportNode> Child)
		{
			ReportTreeView->SetItemExpansion(Child, true);
			for (auto& ChildChild : Child->Children)
			{
				Expand(ChildChild);
			}
		};
		Expand(PackageReportRootNode.Children[0]);
	}
}

void SAssetDumpImporter::OpenPackageReportDialog(const FText& ReportMessage, TArray<ReportPackageData>& PackageNames, const FOnReportConfirmed& InOnReportConfirmed)
{
	TSharedRef<SWindow> ReportWindow = SNew(SWindow)
		.Title(LOCTEXT("ReportWindowTitle", "Asset Report"))
		.ClientSize( FVector2D(600, 500) )
		.SupportsMaximize(false)
		.SupportsMinimize(false)
		[
			SNew(SAssetDumpImporter, ReportMessage, PackageNames, InOnReportConfirmed)
		];
		
	IMainFrameModule& MainFrameModule = FModuleManager::LoadModuleChecked<IMainFrameModule>(TEXT("MainFrame"));
	if ( MainFrameModule.GetParentWindow().IsValid() )
	{
		FSlateApplication::Get().AddWindowAsNativeChild(ReportWindow, MainFrameModule.GetParentWindow().ToSharedRef());
	}
	else
	{
		FSlateApplication::Get().AddWindow(ReportWindow);
	}
}

void SAssetDumpImporter::CloseDialog()
{
	TSharedPtr<SWindow> Window = FSlateApplication::Get().FindWidgetWindow(AsShared());

	if ( Window.IsValid() )
	{
		Window->RequestDestroyWindow();
	}
}

TSharedRef<ITableRow> SAssetDumpImporter::GenerateTreeRow( TSharedPtr<FPackageReportNode> TreeItem, const TSharedRef<STableViewBase>& OwnerTable)
{
	check(TreeItem.IsValid());

	const FSlateBrush* IconBrush = GetNodeIcon(TreeItem);

	return SNew( STableRow< TSharedPtr<FPackageReportNode> >, OwnerTable )
		[
			// Icon
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SCheckBox)
				.OnCheckStateChanged(this, &SAssetDumpImporter::CheckBoxStateChanged, TreeItem, OwnerTable)
				.IsChecked(this, &SAssetDumpImporter::GetEnabledCheckState, TreeItem)
			]
			+SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SImage).Image(IconBrush)
			]
			// Name
			+SHorizontalBox::Slot()
			.FillWidth(1.f)
			[
				SNew(STextBlock).Text(FText::FromString(TreeItem->NodeName))
				.ColorAndOpacity(FSlateColor::UseForeground())
			]
		];
}

ECheckBoxState SAssetDumpImporter::GetEnabledCheckState(TSharedPtr<FPackageReportNode> TreeItem) const
{
	return TreeItem.Get()->CheckedState;
}

void SAssetDumpImporter::SetStateRecursive(TSharedPtr<FPackageReportNode> TreeItem, bool bIsChecked)
{
	if (TreeItem.Get() == nullptr)
	{
		return;
	}

	TreeItem.Get()->CheckedState = bIsChecked ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;

	if (TreeItem.Get()->bShouldMigratePackage)
	{
		*(TreeItem.Get()->bShouldMigratePackage) = bIsChecked;
	}

	TArray< TSharedPtr<FPackageReportNode> > Children;
	GetChildrenForTree(TreeItem, Children);
	for (int i = 0; i < Children.Num(); i++)
	{
		if (Children[i].Get() == nullptr)
		{
			continue;
		}

		SetStateRecursive(Children[i], bIsChecked);
	}
}

void SAssetDumpImporter::CheckBoxStateChanged(ECheckBoxState InCheckBoxState, TSharedPtr<FPackageReportNode> TreeItem, TSharedRef<STableViewBase> OwnerTable)
{
	SetStateRecursive(TreeItem, InCheckBoxState == ECheckBoxState::Checked);

	FPackageReportNode* CurrentParent = TreeItem->Parent;
	while (CurrentParent != nullptr)
	{
		bool bAnyChildIsChecked = false;
		bool bAllChildrenAreChecked = true;
		for (int i = 0; i < CurrentParent->Children.Num(); i++)
		{
			bAnyChildIsChecked |= CurrentParent->Children[i]->CheckedState != ECheckBoxState::Unchecked;
			bAllChildrenAreChecked &= CurrentParent->Children[i]->CheckedState != ECheckBoxState::Unchecked;
		}

		CurrentParent->CheckedState = bAllChildrenAreChecked ? ECheckBoxState::Checked : (bAnyChildIsChecked ? ECheckBoxState::Undetermined : ECheckBoxState::Unchecked);
		CurrentParent = CurrentParent->Parent;
	}

	OwnerTable.Get().RebuildList();
}

void SAssetDumpImporter::GetChildrenForTree( TSharedPtr<FPackageReportNode> TreeItem, TArray< TSharedPtr<FPackageReportNode> >& OutChildren )
{
	OutChildren = TreeItem->Children;
}

void SAssetDumpImporter::ConstructNodeTree(TArray<ReportPackageData>& PackageNames)
{
	PackageReportRootNode.Children.Empty(); // Clear any existing nodes
	OriginalNodes.Reset();
	
	for (ReportPackageData& Package : PackageNames)
	{
		PackageReportRootNode.AddPackage(Package.Entry.PackagePath + "/" + Package.Entry.AssetName.ToString(), &Package.bShouldMigratePackage);
		OriginalNodes.Add({Package.Entry, &Package.bShouldMigratePackage});
	}
}

const FSlateBrush* SAssetDumpImporter::GetNodeIcon(const TSharedPtr<FPackageReportNode>& ReportNode) const
{
	if ( !ReportNode->bIsFolder )
	{
		return PackageBrush;
	}
	else if ( ReportTreeView->IsItemExpanded(ReportNode) )
	{
		return FolderOpenBrush;
	}
	else
	{
		return FolderClosedBrush;
	}
}

FReply SAssetDumpImporter::OkClicked()
{
	CloseDialog();
	OnReportConfirmed.ExecuteIfBound();

	return FReply::Handled();
}

FReply SAssetDumpImporter::CancelClicked()
{
	CloseDialog();

	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
