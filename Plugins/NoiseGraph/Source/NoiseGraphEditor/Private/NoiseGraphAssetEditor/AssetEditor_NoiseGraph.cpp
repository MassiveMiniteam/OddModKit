#include "NoiseGraphAssetEditor/AssetEditor_NoiseGraph.h"

#include "AdvancedPreviewScene.h"
#include "AdvancedPreviewSceneModule.h"
#include "NoiseGraphEditorPCH.h"
#include "NoiseGraphAssetEditor/AssetEditorToolbar_NoiseGraph.h"
#include "NoiseGraphAssetEditor/AssetGraphSchema_NoiseGraph.h"
#include "NoiseGraphAssetEditor/EditorCommands_NoiseGraph.h"
#include "NoiseGraphAssetEditor/EdGraph_NoiseGraph.h"
#include "AssetToolsModule.h"
#include "HAL/PlatformApplicationMisc.h"
#include "Framework/Commands/GenericCommands.h"
#include "GraphEditorActions.h"
#include "IDetailsView.h"
#include "PropertyEditorModule.h"
#include "Editor/UnrealEd/Public/Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "EdGraphUtilities.h"
#include "Kismet/KismetMathLibrary.h"
#include "NoiseGraphAssetEditor/EdGraph_NoiseGraph.h"
#include "NoiseGraphAssetEditor/EdNode_NoiseGraphNode.h"
#include "NoiseGraphAssetEditor/EdNode_NoiseGraphEdge.h"
#include "NoiseGraphAssetEditor/SEdNode_NoiseGraphNode.h"
#include "Slate/SceneViewport.h"
#include "Widgets/SViewport.h"

#define LOCTEXT_NAMESPACE "AssetEditor_NoiseGraph"

const FName NoiseGraphEditorAppName = FName(TEXT("NoiseGraphEditorApp"));

struct FNoiseGraphAssetEditorTabs
{
	// Tab identifiers
	static const FName NoiseGraphPropertyID;
	static const FName ViewportID;
	static const FName NoiseGraphEditorSettingsID;
	static const FName NoiseGraphEditorPreviewID;
};

//////////////////////////////////////////////////////////////////////////

const FName FNoiseGraphAssetEditorTabs::NoiseGraphPropertyID(TEXT("NoiseGraphProperty"));
const FName FNoiseGraphAssetEditorTabs::ViewportID(TEXT("Viewport"));
const FName FNoiseGraphAssetEditorTabs::NoiseGraphEditorSettingsID(TEXT("NoiseGraphEditorSettings"));
const FName FNoiseGraphAssetEditorTabs::NoiseGraphEditorPreviewID(TEXT("NoiseGraphEditorPreview"));

//////////////////////////////////////////////////////////////////////////

FAssetEditor_NoiseGraph::FAssetEditor_NoiseGraph()
{
	EditingGraph = nullptr;

	GenricGraphEditorSettings = NewObject<UNoiseGraphEditorSettings>(UNoiseGraphEditorSettings::StaticClass());

#if ENGINE_MAJOR_VERSION < 5
	OnPackageSavedDelegateHandle = UPackage::PackageSavedEvent.AddRaw(this, &FAssetEditor_NoiseGraph::OnPackageSaved);
#else // #if ENGINE_MAJOR_VERSION < 5
	OnPackageSavedDelegateHandle = UPackage::PackageSavedWithContextEvent.AddRaw(this, &FAssetEditor_NoiseGraph::OnPackageSavedWithContext);
#endif // #else // #if ENGINE_MAJOR_VERSION < 5
}

FAssetEditor_NoiseGraph::~FAssetEditor_NoiseGraph()
{
#if ENGINE_MAJOR_VERSION < 5
	UPackage::PackageSavedEvent.Remove(OnPackageSavedDelegateHandle);
#else // #if ENGINE_MAJOR_VERSION < 5
	UPackage::PackageSavedWithContextEvent.Remove(OnPackageSavedDelegateHandle);
#endif // #else // #if ENGINE_MAJOR_VERSION < 5

	// Close viewport
	if( Client.IsValid() )
	{
		Client->Viewport = NULL;
	}

	// Release our reference to the viewport client
	Client.Reset();
}

void FAssetEditor_NoiseGraph::InitNoiseGraphAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UNoiseGraph* Graph)
{
	EditingGraph = Graph;
	CreateEdGraph();

	FGenericCommands::Register();
	FGraphEditorCommands::Register();
	FEditorCommands_NoiseGraph::Register();

	if (!ToolbarBuilder.IsValid())
	{
		ToolbarBuilder = MakeShareable(new FAssetEditorToolbar_NoiseGraph(SharedThis(this)));
	}

	BindCommands();

	CreateInternalWidgets();

	TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);

	ToolbarBuilder->AddNoiseGraphToolbar(ToolbarExtender);

	// Layout
	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_NoiseGraphEditor_Layout_v1")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
#if ENGINE_MAJOR_VERSION < 5
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.1f)
				->AddTab(GetToolbarTabId(), ETabState::OpenedTab)->SetHideTabWell(true)
			)
#endif // #if ENGINE_MAJOR_VERSION < 5
			->Split
			(
				FTabManager::NewSplitter()->SetOrientation(Orient_Horizontal)->SetSizeCoefficient(0.9f)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.65f)
					->AddTab(FNoiseGraphAssetEditorTabs::ViewportID, ETabState::OpenedTab)->SetHideTabWell(true)
				)
				->Split
				(
				FTabManager::NewSplitter()->SetOrientation(Orient_Vertical)
					->Split
					(
						FTabManager::NewStack()
						->SetSizeCoefficient(0.4f)
						->AddTab(FNoiseGraphAssetEditorTabs::NoiseGraphPropertyID, ETabState::OpenedTab)->SetHideTabWell(true)
					)
					->Split
					(
						FTabManager::NewStack()
						->SetSizeCoefficient(0.3f)
						->AddTab(FNoiseGraphAssetEditorTabs::NoiseGraphEditorPreviewID, ETabState::OpenedTab)->SetHideTabWell(true)
					)
					->Split
					(
						FTabManager::NewStack()
						->SetSizeCoefficient(0.3f)
						->AddTab(FNoiseGraphAssetEditorTabs::NoiseGraphEditorSettingsID, ETabState::OpenedTab)
					)
				)
			)
		);

	const bool bCreateDefaultStandaloneMenu = true;
	const bool bCreateDefaultToolbar = true;
	FAssetEditorToolkit::InitAssetEditor(Mode, InitToolkitHost, NoiseGraphEditorAppName, StandaloneDefaultLayout, bCreateDefaultStandaloneMenu, bCreateDefaultToolbar, EditingGraph, false);

	RegenerateMenusAndToolbars();
}

void FAssetEditor_NoiseGraph::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_NoiseGraphEditor", "Noise Graph Editor"));
	auto WorkspaceMenuCategoryRef = WorkspaceMenuCategory.ToSharedRef();

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(FNoiseGraphAssetEditorTabs::ViewportID, FOnSpawnTab::CreateSP(this, &FAssetEditor_NoiseGraph::SpawnTab_Viewport))
		.SetDisplayName(LOCTEXT("GraphCanvasTab", "Viewport"))
		.SetGroup(WorkspaceMenuCategoryRef)
	.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "GraphEditor.EventGraph_16x"));

	InTabManager->RegisterTabSpawner(FNoiseGraphAssetEditorTabs::NoiseGraphPropertyID, FOnSpawnTab::CreateSP(this, &FAssetEditor_NoiseGraph::SpawnTab_Details))
		.SetDisplayName(LOCTEXT("DetailsTab", "Property"))
		.SetGroup(WorkspaceMenuCategoryRef)
	.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Details"));

	InTabManager->RegisterTabSpawner(FNoiseGraphAssetEditorTabs::NoiseGraphEditorPreviewID, FOnSpawnTab::CreateSP(this, &FAssetEditor_NoiseGraph::SpawnTab_Preview))
		.SetDisplayName(LOCTEXT("PreviewTab", "Property"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Preview"));

	InTabManager->RegisterTabSpawner(FNoiseGraphAssetEditorTabs::NoiseGraphEditorSettingsID, FOnSpawnTab::CreateSP(this, &FAssetEditor_NoiseGraph::SpawnTab_EditorSettings))
		.SetDisplayName(LOCTEXT("EditorSettingsTab", "Noise Graph Editor Setttings"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Details"));
}

void FAssetEditor_NoiseGraph::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(FNoiseGraphAssetEditorTabs::ViewportID);
	InTabManager->UnregisterTabSpawner(FNoiseGraphAssetEditorTabs::NoiseGraphPropertyID);
	InTabManager->UnregisterTabSpawner(FNoiseGraphAssetEditorTabs::NoiseGraphEditorPreviewID);
	InTabManager->UnregisterTabSpawner(FNoiseGraphAssetEditorTabs::NoiseGraphEditorSettingsID);
}

FName FAssetEditor_NoiseGraph::GetToolkitFName() const
{
	return FName("FNoiseGraphEditor");
}

FText FAssetEditor_NoiseGraph::GetBaseToolkitName() const
{
	return LOCTEXT("NoiseGraphEditorAppLabel", "Noise Graph Editor");
}

FText FAssetEditor_NoiseGraph::GetToolkitName() const
{
	const bool bDirtyState = EditingGraph->GetOutermost()->IsDirty();

	FFormatNamedArguments Args;
	Args.Add(TEXT("NoiseGraphName"), FText::FromString(EditingGraph->GetName()));
	Args.Add(TEXT("DirtyState"), bDirtyState ? FText::FromString(TEXT("*")) : FText::GetEmpty());
	return FText::Format(LOCTEXT("NoiseGraphEditorToolkitName", "{NoiseGraphName}{DirtyState}"), Args);
}

FText FAssetEditor_NoiseGraph::GetToolkitToolTipText() const
{
	return FAssetEditorToolkit::GetToolTipTextForObject(EditingGraph);
}

FLinearColor FAssetEditor_NoiseGraph::GetWorldCentricTabColorScale() const
{
	return FLinearColor::White;
}

FString FAssetEditor_NoiseGraph::GetWorldCentricTabPrefix() const
{
	return TEXT("NoiseGraphEditor");
}

FString FAssetEditor_NoiseGraph::GetDocumentationLink() const
{
	return TEXT("");
}

void FAssetEditor_NoiseGraph::SaveAsset_Execute()
{
	if (EditingGraph != nullptr)
	{
		RebuildNoiseGraph();
	}

	FAssetEditorToolkit::SaveAsset_Execute();
}

void FAssetEditor_NoiseGraph::AddReferencedObjects(FReferenceCollector& Collector)
{
	Collector.AddReferencedObject(EditingGraph);
	Collector.AddReferencedObject(EditingGraph->EdGraph);
}

UNoiseGraphEditorSettings* FAssetEditor_NoiseGraph::GetSettings() const
{
	return GenricGraphEditorSettings;
}

TSharedRef<SDockTab> FAssetEditor_NoiseGraph::SpawnTab_Viewport(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == FNoiseGraphAssetEditorTabs::ViewportID);

	TSharedRef<SDockTab> SpawnedTab = SNew(SDockTab)
		.Label(LOCTEXT("ViewportTab_Title", "Viewport"));

	if (ViewportWidget.IsValid())
	{
		SpawnedTab->SetContent(ViewportWidget.ToSharedRef());
	}

	return SpawnedTab;
}

TSharedRef<SDockTab> FAssetEditor_NoiseGraph::SpawnTab_Details(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == FNoiseGraphAssetEditorTabs::NoiseGraphPropertyID);

	return SNew(SDockTab)
#if ENGINE_MAJOR_VERSION < 5
		.Icon(FEditorStyle::GetBrush("LevelEditor.Tabs.Details"))
#endif // #if ENGINE_MAJOR_VERSION < 5
	.Label(LOCTEXT("Details_Title", "Property"))
	[
		PropertyWidget.ToSharedRef()
	];
}

TSharedRef<SDockTab> FAssetEditor_NoiseGraph::SpawnTab_Preview(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == FNoiseGraphAssetEditorTabs::NoiseGraphEditorPreviewID);

	return SNew(SDockTab)
#if ENGINE_MAJOR_VERSION < 5
		.Icon(FEditorStyle::GetBrush("LevelEditor.Tabs.Preview"))
#endif // #if ENGINE_MAJOR_VERSION < 5
	.Label(LOCTEXT("Preview_Title", "Preview"))
	[
		BigPreviewWidget.ToSharedRef()
	];
}

TSharedRef<SDockTab> FAssetEditor_NoiseGraph::SpawnTab_EditorSettings(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == FNoiseGraphAssetEditorTabs::NoiseGraphEditorSettingsID);

	return SNew(SDockTab)
#if ENGINE_MAJOR_VERSION < 5
		.Icon(FEditorStyle::GetBrush("LevelEditor.Tabs.Details"))
#endif // #if ENGINE_MAJOR_VERSION < 5
		.Label(LOCTEXT("EditorSettings_Title", "Noise Graph Editor Setttings"))
		[
			EditorSettingsWidget.ToSharedRef()
		];
}

void FAssetEditor_NoiseGraph::CreateInternalWidgets()
{
	ViewportWidget = CreateViewportWidget();

	FDetailsViewArgs Args;
	Args.bHideSelectionTip = true;
	Args.NotifyHook = this;
	
	AdvancedPreviewScene = MakeShareable(new FAdvancedPreviewScene(FPreviewScene::ConstructionValues()));
	PreviewViewportWidget = SNew(SViewport);

	BigPreviewWidget = SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						.VAlign(VAlign_Fill)
						.HAlign(HAlign_Fill)
						.Padding(2)
						[
							SNew(SImage).Image(&BigPreviewBrush)
						];
	
	Client = MakeShareable(new FEditorViewportClient(nullptr, AdvancedPreviewScene.Get()));
	SceneViewport = MakeShareable( new FSceneViewport( Client.Get(), PreviewViewportWidget ) );
	Client->Viewport = SceneViewport.Get();
	PreviewViewportWidget->SetViewportInterface(SceneViewport.ToSharedRef());

	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyWidget = PropertyModule.CreateDetailView(Args);
	PropertyWidget->SetObject(EditingGraph);
	PropertyWidget->OnFinishedChangingProperties().AddSP(this, &FAssetEditor_NoiseGraph::OnFinishedChangingProperties);

	EditorSettingsWidget = PropertyModule.CreateDetailView(Args);
	EditorSettingsWidget->SetObject(GenricGraphEditorSettings);

	UpdatePreview();

	AdvancedPreviewScene->SetEnvironmentVisibility(false);
	AdvancedPreviewScene->SetFloorVisibility(false);

	Client->SetViewLocation( FVector::ZeroVector );
	Client->SetViewRotation( FRotator(-15.0f, -90.0f, 0.0f) );
	Client->SetViewLocationForOrbiting( FVector::ZeroVector );
	Client->bSetListenerPosition = false;
	Client->EngineShowFlags.EnableAdvancedFeatures();
	Client->EngineShowFlags.SetLighting(true);
	Client->EngineShowFlags.SetIndirectLightingCache(true);
	Client->EngineShowFlags.SetPostProcessing(true);
	Client->Invalidate();
}

void FAssetEditor_NoiseGraph::UpdatePreview()
{
	GeneratePreviews();
	
	/*UGraphNoiseNodeMaster* MasterNode = nullptr;
	for (UNoiseGraphNode* Node : EditingGraph->AllNodes)
	{
		if (Node->IsA(UGraphNoiseNodeMaster::StaticClass()))
		{
			MasterNode = Cast<UGraphNoiseNodeMaster>(Node);
			break;
		}
	}

	if (MasterNode != nullptr)
	{
		TScriptInterface<INoiseModuleInterface> PosModule = MasterNode->GetNoiseModule(0);
		TScriptInterface<INoiseModuleInterface> ColorModule = MasterNode->GetColorModule(0);

		if (!PosModule || !ColorModule)
		{
			return;
		}

		if (ProceduralMeshComponent == nullptr || !IsValid(ProceduralMeshComponent))
		{
			ProceduralMeshComponent = NewObject<UProceduralMeshComponent>(GetTransientPackage());
			ProceduralMeshComponent->SetMaterial(0, EditingGraph->Material);
			FTransform CenterTransform(FRotator(0, 0, 0), FVector(0, 0, 0), FVector(1.0f, 1.0f, 1.0f ) * 1);
			AdvancedPreviewScene->AddComponent(ProceduralMeshComponent, CenterTransform);
		}

		UNoiseGen::GenerateNoiseSphere(50, 100, Cast<UNoiseModule>(PosModule.GetObject()), Cast<UNoiseModule>(ColorModule.GetObject()), EditingGraph->ColorCurve, ProceduralMeshComponent);

		Client->Invalidate();
		Client->Viewport->Invalidate();
		PreviewViewportWidget.ToSharedRef()->Invalidate(EInvalidateWidgetReason::Paint);
		PreviewViewportWidget.ToSharedRef()->SlatePrepass();
		Client->Viewport->InvalidateDisplay();
		Client->Viewport->Draw();
	}*/
}

TSharedRef<SGraphEditor> FAssetEditor_NoiseGraph::CreateViewportWidget()
{
	FGraphAppearanceInfo AppearanceInfo;
	AppearanceInfo.CornerText = LOCTEXT("AppearanceCornerText_NoiseGraph", "Noise Graph");

	CreateCommandList();

	SGraphEditor::FGraphEditorEvents InEvents;
	InEvents.OnSelectionChanged = SGraphEditor::FOnSelectionChanged::CreateSP(this, &FAssetEditor_NoiseGraph::OnSelectedNodesChanged);
	InEvents.OnNodeDoubleClicked = FSingleNodeEvent::CreateSP(this, &FAssetEditor_NoiseGraph::OnNodeDoubleClicked);

	return SNew(SGraphEditor)
		.AdditionalCommands(GraphEditorCommands)
		.IsEditable(true)
		.Appearance(AppearanceInfo)
		.GraphToEdit(EditingGraph->EdGraph)
		.GraphEvents(InEvents)
		.AutoExpandActionMenu(true)
		.ShowGraphStateOverlay(false);
}

void FAssetEditor_NoiseGraph::BindCommands()
{
	ToolkitCommands->MapAction(FEditorCommands_NoiseGraph::Get().GraphSettings,
		FExecuteAction::CreateSP(this, &FAssetEditor_NoiseGraph::GraphSettings),
		FCanExecuteAction::CreateSP(this, &FAssetEditor_NoiseGraph::CanGraphSettings)
	);

	ToolkitCommands->MapAction(FEditorCommands_NoiseGraph::Get().GeneratePreviews,
		FExecuteAction::CreateSP(this, &FAssetEditor_NoiseGraph::GeneratePreviews),
		FCanExecuteAction::CreateSP(this, &FAssetEditor_NoiseGraph::CanGeneratePreviews)
	);
}

void FAssetEditor_NoiseGraph::CreateEdGraph()
{
	if (EditingGraph->EdGraph == nullptr)
	{
		EditingGraph->EdGraph = CastChecked<UEdGraph_NoiseGraph>(FBlueprintEditorUtils::CreateNewGraph(EditingGraph, NAME_None, UEdGraph_NoiseGraph::StaticClass(), UAssetGraphSchema_NoiseGraph::StaticClass()));
		EditingGraph->EdGraph->bAllowDeletion = false;

		// Give the schema a chance to fill out any required nodes (like the results node)
		const UEdGraphSchema* Schema = EditingGraph->EdGraph->GetSchema();
		Schema->CreateDefaultNodesForGraph(*EditingGraph->EdGraph);
	}
}

void FAssetEditor_NoiseGraph::CreateCommandList()
{
	if (GraphEditorCommands.IsValid())
	{
		return;
	}

	GraphEditorCommands = MakeShareable(new FUICommandList);

	// Can't use CreateSP here because derived editor are already implementing TSharedFromThis<FAssetEditorToolkit>
	// however it should be safe, since commands are being used only within this editor
	// if it ever crashes, this function will have to go away and be reimplemented in each derived class

	GraphEditorCommands->MapAction(FEditorCommands_NoiseGraph::Get().GraphSettings,
		FExecuteAction::CreateRaw(this, &FAssetEditor_NoiseGraph::GraphSettings),
		FCanExecuteAction::CreateRaw(this, &FAssetEditor_NoiseGraph::CanGraphSettings));

	GraphEditorCommands->MapAction(FEditorCommands_NoiseGraph::Get().GeneratePreviews,
		FExecuteAction::CreateRaw(this, &FAssetEditor_NoiseGraph::GeneratePreviews),
		FCanExecuteAction::CreateRaw(this, &FAssetEditor_NoiseGraph::CanGeneratePreviews));

	GraphEditorCommands->MapAction(FGenericCommands::Get().SelectAll,
		FExecuteAction::CreateRaw(this, &FAssetEditor_NoiseGraph::SelectAllNodes),
		FCanExecuteAction::CreateRaw(this, &FAssetEditor_NoiseGraph::CanSelectAllNodes)
	);

	GraphEditorCommands->MapAction(FGenericCommands::Get().Delete,
		FExecuteAction::CreateRaw(this, &FAssetEditor_NoiseGraph::DeleteSelectedNodes),
		FCanExecuteAction::CreateRaw(this, &FAssetEditor_NoiseGraph::CanDeleteNodes)
	);

	GraphEditorCommands->MapAction(FGenericCommands::Get().Copy,
		FExecuteAction::CreateRaw(this, &FAssetEditor_NoiseGraph::CopySelectedNodes),
		FCanExecuteAction::CreateRaw(this, &FAssetEditor_NoiseGraph::CanCopyNodes)
	);

	GraphEditorCommands->MapAction(FGenericCommands::Get().Cut,
		FExecuteAction::CreateRaw(this, &FAssetEditor_NoiseGraph::CutSelectedNodes),
		FCanExecuteAction::CreateRaw(this, &FAssetEditor_NoiseGraph::CanCutNodes)
	);

	GraphEditorCommands->MapAction(FGenericCommands::Get().Paste,
		FExecuteAction::CreateRaw(this, &FAssetEditor_NoiseGraph::PasteNodes),
		FCanExecuteAction::CreateRaw(this, &FAssetEditor_NoiseGraph::CanPasteNodes)
	);

	GraphEditorCommands->MapAction(FGenericCommands::Get().Duplicate,
		FExecuteAction::CreateRaw(this, &FAssetEditor_NoiseGraph::DuplicateNodes),
		FCanExecuteAction::CreateRaw(this, &FAssetEditor_NoiseGraph::CanDuplicateNodes)
	);
}

TSharedPtr<SGraphEditor> FAssetEditor_NoiseGraph::GetCurrGraphEditor() const
{
	return ViewportWidget;
}

FGraphPanelSelectionSet FAssetEditor_NoiseGraph::GetSelectedNodes() const
{
	FGraphPanelSelectionSet CurrentSelection;
	TSharedPtr<SGraphEditor> FocusedGraphEd = GetCurrGraphEditor();
	if (FocusedGraphEd.IsValid())
	{
		CurrentSelection = FocusedGraphEd->GetSelectedNodes();
	}

	return CurrentSelection;
}

void FAssetEditor_NoiseGraph::RebuildNoiseGraph()
{
	if (EditingGraph == nullptr)
	{
		LOG_WARNING(TEXT("FNoiseGraphAssetEditor::RebuildNoiseGraph EditingGraph is nullptr"));
		return;
	}

	UEdGraph_NoiseGraph* EdGraph = Cast<UEdGraph_NoiseGraph>(EditingGraph->EdGraph);
	check(EdGraph != nullptr);

	EdGraph->RebuildNoiseGraph();
	UpdatePreview();
}

void FAssetEditor_NoiseGraph::SelectAllNodes()
{
	TSharedPtr<SGraphEditor> CurrentGraphEditor = GetCurrGraphEditor();
	if (CurrentGraphEditor.IsValid())
	{
		CurrentGraphEditor->SelectAllNodes();
	}
}

bool FAssetEditor_NoiseGraph::CanSelectAllNodes()
{
	return true;
}

void FAssetEditor_NoiseGraph::DeleteSelectedNodes()
{
	TSharedPtr<SGraphEditor> CurrentGraphEditor = GetCurrGraphEditor();
	if (!CurrentGraphEditor.IsValid())
	{
		return;
	}

	const FScopedTransaction Transaction(FGenericCommands::Get().Delete->GetDescription());

	CurrentGraphEditor->GetCurrentGraph()->Modify();

	const FGraphPanelSelectionSet SelectedNodes = CurrentGraphEditor->GetSelectedNodes();
	CurrentGraphEditor->ClearSelectionSet();

	for (FGraphPanelSelectionSet::TConstIterator NodeIt(SelectedNodes); NodeIt; ++NodeIt)
	{
		UEdGraphNode* EdNode = Cast<UEdGraphNode>(*NodeIt);
		if (EdNode == nullptr || !EdNode->CanUserDeleteNode())
			continue;;

		if (UEdNode_NoiseGraphNode* EdNode_Node = Cast<UEdNode_NoiseGraphNode>(EdNode))
		{
			EdNode_Node->Modify();

			const UEdGraphSchema* Schema = EdNode_Node->GetSchema();
			if (Schema != nullptr)
			{
				Schema->BreakNodeLinks(*EdNode_Node);
			}

			EdNode_Node->DestroyNode();
		}
		else
		{
			EdNode->Modify();
			EdNode->DestroyNode();
		}
	}
}

bool FAssetEditor_NoiseGraph::CanDeleteNodes()
{
	// If any of the nodes can be deleted then we should allow deleting
	const FGraphPanelSelectionSet SelectedNodes = GetSelectedNodes();
	for (FGraphPanelSelectionSet::TConstIterator SelectedIter(SelectedNodes); SelectedIter; ++SelectedIter)
	{
		UEdGraphNode* Node = Cast<UEdGraphNode>(*SelectedIter);
		if (Node != nullptr && Node->CanUserDeleteNode())
		{
			return true;
		}
	}

	return false;
}

void FAssetEditor_NoiseGraph::DeleteSelectedDuplicatableNodes()
{
	TSharedPtr<SGraphEditor> CurrentGraphEditor = GetCurrGraphEditor();
	if (!CurrentGraphEditor.IsValid())
	{
		return;
	}

	const FGraphPanelSelectionSet OldSelectedNodes = CurrentGraphEditor->GetSelectedNodes();
	CurrentGraphEditor->ClearSelectionSet();

	for (FGraphPanelSelectionSet::TConstIterator SelectedIter(OldSelectedNodes); SelectedIter; ++SelectedIter)
	{
		UEdGraphNode* Node = Cast<UEdGraphNode>(*SelectedIter);
		if (Node && Node->CanDuplicateNode())
		{
			CurrentGraphEditor->SetNodeSelection(Node, true);
		}
	}

	// Delete the duplicatable nodes
	DeleteSelectedNodes();

	CurrentGraphEditor->ClearSelectionSet();

	for (FGraphPanelSelectionSet::TConstIterator SelectedIter(OldSelectedNodes); SelectedIter; ++SelectedIter)
	{
		if (UEdGraphNode* Node = Cast<UEdGraphNode>(*SelectedIter))
		{
			CurrentGraphEditor->SetNodeSelection(Node, true);
		}
	}
}

void FAssetEditor_NoiseGraph::CutSelectedNodes()
{
	CopySelectedNodes();
	DeleteSelectedDuplicatableNodes();
}

bool FAssetEditor_NoiseGraph::CanCutNodes()
{
	return CanCopyNodes() && CanDeleteNodes();
}

void FAssetEditor_NoiseGraph::CopySelectedNodes()
{
	// Export the selected nodes and place the text on the clipboard
	FGraphPanelSelectionSet SelectedNodes = GetSelectedNodes();

	FString ExportedText;

	for (FGraphPanelSelectionSet::TIterator SelectedIter(SelectedNodes); SelectedIter; ++SelectedIter)
	{
		UEdGraphNode* Node = Cast<UEdGraphNode>(*SelectedIter);
		if (Node == nullptr)
		{
			SelectedIter.RemoveCurrent();
			continue;
		}

		if (UEdNode_NoiseGraphEdge* EdNode_Edge = Cast<UEdNode_NoiseGraphEdge>(*SelectedIter))
		{
			UEdNode_NoiseGraphNode* StartNode = EdNode_Edge->GetStartNode();
			UEdNode_NoiseGraphNode* EndNode = EdNode_Edge->GetEndNode();

			if (!SelectedNodes.Contains(StartNode) || !SelectedNodes.Contains(EndNode))
			{
				SelectedIter.RemoveCurrent();
				continue;
			}
		}

		Node->PrepareForCopying();
	}

	FEdGraphUtilities::ExportNodesToText(SelectedNodes, ExportedText);
	FPlatformApplicationMisc::ClipboardCopy(*ExportedText);
}

bool FAssetEditor_NoiseGraph::CanCopyNodes()
{
	// If any of the nodes can be duplicated then we should allow copying
	const FGraphPanelSelectionSet SelectedNodes = GetSelectedNodes();
	for (FGraphPanelSelectionSet::TConstIterator SelectedIter(SelectedNodes); SelectedIter; ++SelectedIter)
	{
		UEdGraphNode* Node = Cast<UEdGraphNode>(*SelectedIter);
		if (Node && Node->CanDuplicateNode())
		{
			return true;
		}
	}

	return false;
}

void FAssetEditor_NoiseGraph::PasteNodes()
{
	TSharedPtr<SGraphEditor> CurrentGraphEditor = GetCurrGraphEditor();
	if (CurrentGraphEditor.IsValid())
	{
		PasteNodesHere(CurrentGraphEditor->GetPasteLocation());
	}
}

void FAssetEditor_NoiseGraph::PasteNodesHere(const FVector2D& Location)
{
	// Find the graph editor with focus
	TSharedPtr<SGraphEditor> CurrentGraphEditor = GetCurrGraphEditor();
	if (!CurrentGraphEditor.IsValid())
	{
		return;
	}
	// Select the newly pasted stuff
	UEdGraph* EdGraph = CurrentGraphEditor->GetCurrentGraph();

	{
		const FScopedTransaction Transaction(FGenericCommands::Get().Paste->GetDescription());
		EdGraph->Modify();

		// Clear the selection set (newly pasted stuff will be selected)
		CurrentGraphEditor->ClearSelectionSet();

		// Grab the text to paste from the clipboard.
		FString TextToImport;
		FPlatformApplicationMisc::ClipboardPaste(TextToImport);

		// Import the nodes
		TSet<UEdGraphNode*> PastedNodes;
		FEdGraphUtilities::ImportNodesFromText(EdGraph, TextToImport, PastedNodes);

		//Average position of nodes so we can move them while still maintaining relative distances to each other
		FVector2D AvgNodePosition(0.0f, 0.0f);

		for (TSet<UEdGraphNode*>::TIterator It(PastedNodes); It; ++It)
		{
			UEdGraphNode* Node = *It;
			AvgNodePosition.X += Node->NodePosX;
			AvgNodePosition.Y += Node->NodePosY;
		}

		float InvNumNodes = 1.0f / float(PastedNodes.Num());
		AvgNodePosition.X *= InvNumNodes;
		AvgNodePosition.Y *= InvNumNodes;

		for (TSet<UEdGraphNode*>::TIterator It(PastedNodes); It; ++It)
		{
			UEdGraphNode* Node = *It;
			CurrentGraphEditor->SetNodeSelection(Node, true);

			Node->NodePosX = (Node->NodePosX - AvgNodePosition.X) + Location.X;
			Node->NodePosY = (Node->NodePosY - AvgNodePosition.Y) + Location.Y;

			Node->SnapToGrid(16);

			// Give new node a different Guid from the old one
			Node->CreateNewGuid();
		}
	}

	// Update UI
	CurrentGraphEditor->NotifyGraphChanged();

	UObject* GraphOwner = EdGraph->GetOuter();
	if (GraphOwner)
	{
		GraphOwner->PostEditChange();
		GraphOwner->MarkPackageDirty();
	}
}

bool FAssetEditor_NoiseGraph::CanPasteNodes()
{
	TSharedPtr<SGraphEditor> CurrentGraphEditor = GetCurrGraphEditor();
	if (!CurrentGraphEditor.IsValid())
	{
		return false;
	}

	FString ClipboardContent;
	FPlatformApplicationMisc::ClipboardPaste(ClipboardContent);

	return FEdGraphUtilities::CanImportNodesFromText(CurrentGraphEditor->GetCurrentGraph(), ClipboardContent);
}

void FAssetEditor_NoiseGraph::DuplicateNodes()
{
	CopySelectedNodes();
	PasteNodes();
}

bool FAssetEditor_NoiseGraph::CanDuplicateNodes()
{
	return CanCopyNodes();
}

void FAssetEditor_NoiseGraph::GraphSettings()
{
	PropertyWidget->SetObject(EditingGraph);
}

bool FAssetEditor_NoiseGraph::CanGraphSettings() const
{
	return true;
}

bool FAssetEditor_NoiseGraph::CanGeneratePreviews() const
{
	return true;
}

void FAssetEditor_NoiseGraph::GeneratePreviews()
{
	UEdGraph_NoiseGraph* EdGraph = Cast<UEdGraph_NoiseGraph>(EditingGraph->EdGraph);
	check(EdGraph != nullptr);

	int Seed = UKismetMathLibrary::RandomInteger(100000);

	for (auto Node : EdGraph->Nodes)
	{
		if (auto EdNode = Cast<UEdNode_NoiseGraphNode>(Node))
		{
			if (EdNode->SEdNode != nullptr)
			{
				EdNode->SEdNode->UpdateGraphNodeWithSeed(Seed);
			}
		}
	}
}

void FAssetEditor_NoiseGraph::OnSelectedNodesChanged(const TSet<class UObject*>& NewSelection)
{
	TArray<UObject*> Selection;

	for (UObject* SelectionEntry : NewSelection)
	{
		Selection.Add(SelectionEntry);
		UEdNode_NoiseGraphNode* Node = Cast<UEdNode_NoiseGraphNode>(SelectionEntry);
		if (IsValid(Node) && Node->SEdNode != nullptr && IsValid(Node->SEdNode->PreviewTexture))
		{
			BigPreviewBrush.SetResourceObject(Node->SEdNode->PreviewTexture);
		}
	}

	if (Selection.Num() == 0) 
	{
		PropertyWidget->SetObject(EditingGraph);

	}
	else
	{
		PropertyWidget->SetObjects(Selection);
	}
}

void FAssetEditor_NoiseGraph::OnNodeDoubleClicked(UEdGraphNode* Node)
{
	
}

void FAssetEditor_NoiseGraph::OnFinishedChangingProperties(const FPropertyChangedEvent& PropertyChangedEvent)
{
	if (EditingGraph == nullptr)
		return;

	EditingGraph->EdGraph->GetSchema()->ForceVisualizationCacheClear();
}

#if ENGINE_MAJOR_VERSION < 5
void FAssetEditor_NoiseGraph::OnPackageSaved(const FString& PackageFileName, UObject* Outer)
{
	RebuildNoiseGraph();
}
#else // #if ENGINE_MAJOR_VERSION < 5
void FAssetEditor_NoiseGraph::OnPackageSavedWithContext(const FString& PackageFileName, UPackage* Package, FObjectPostSaveContext ObjectSaveContext)
{
	RebuildNoiseGraph();
}
#endif // #else // #if ENGINE_MAJOR_VERSION < 5

void FAssetEditor_NoiseGraph::RegisterToolbarTab(const TSharedRef<class FTabManager>& InTabManager) 
{
	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);
}


#undef LOCTEXT_NAMESPACE

