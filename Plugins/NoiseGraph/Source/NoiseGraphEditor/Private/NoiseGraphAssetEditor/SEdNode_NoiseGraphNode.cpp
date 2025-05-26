#include "NoiseGraphAssetEditor/SEdNode_NoiseGraphNode.h"

#include "EditorStyleSet.h"
#include "NoiseGraphEditorPCH.h"
#include "NoiseGraphAssetEditor/Colors_NoiseGraph.h"
#include "SLevelOfDetailBranchNode.h"
#include "Widgets/Text/SInlineEditableTextBlock.h"
#include "SCommentBubble.h"
#include "SlateOptMacros.h"
#include "SGraphPin.h"
#include "GraphEditorSettings.h"
#include "SGraphPanel.h"
#include "Kismet/KismetMathLibrary.h"
#include "NoiseGraphAssetEditor/EdGraph_NoiseGraph.h"
#include "NoiseGraphAssetEditor/EdNode_NoiseGraphNode.h"
#include "NoiseGraphAssetEditor/NoiseGraphDragConnection.h"

#define LOCTEXT_NAMESPACE "EdNode_NoiseGraph"

static const FName NAME_Pin_NotConnectable("Graph.Pin.Dummy");
static const FSlateBrush* CacheImg_Pin_NotConnectable = nullptr;

//////////////////////////////////////////////////////////////////////////
class SNoiseGraphPin : public SGraphPin
{
public:
	SLATE_BEGIN_ARGS(SNoiseGraphPin) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, UEdGraphPin* InPin)
	{
		this->SetCursor(EMouseCursor::Default);

		bShowLabel = true;

		GraphPinObj = InPin;
		check(GraphPinObj != nullptr);

		const UEdGraphSchema* Schema = GraphPinObj->GetSchema();
		check(Schema);

		SBorder::Construct(SBorder::FArguments()
			.BorderImage(this, &SNoiseGraphPin::GetPinBorder)
			.BorderBackgroundColor(this, &SNoiseGraphPin::GetPinColor)
			.OnMouseButtonDown(this, &SNoiseGraphPin::OnPinMouseDown)
			.Cursor(this, &SNoiseGraphPin::GetPinCursor)
			.Padding(FMargin(5.0f))
		);
	}

protected:
	virtual FSlateColor GetPinColor() const override
	{
		return NoiseGraphColors::Pin::Default;
	}

	virtual TSharedRef<SWidget>	GetDefaultValueWidget() override
	{
		return SNew(STextBlock);
	}

	const FSlateBrush* GetPinBorder() const
	{
		return FAppStyle::GetBrush(TEXT("Graph.StateNode.Body"));
	}

	virtual TSharedRef<FDragDropOperation> SpawnPinDragEvent(const TSharedRef<class SGraphPanel>& InGraphPanel, const TArray< TSharedRef<SGraphPin> >& InStartingPins) override
	{
		/*FNoiseGraphDragConnection::FDraggedPinTable PinHandles;
		PinHandles.Reserve(InStartingPins.Num());
		// since the graph can be refreshed and pins can be reconstructed/replaced 
		// behind the scenes, the DragDropOperation holds onto FGraphPinHandles 
		// instead of direct widgets/graph-pins
		for (const TSharedRef<SGraphPin>& PinWidget : InStartingPins)
		{
			PinHandles.Add(PinWidget->GetPinObj());
		}

		return FNoiseGraphDragConnection::New(InGraphPanel, PinHandles);*/
		return SGraphPin::SpawnPinDragEvent(InGraphPanel, InStartingPins);
	}

};


//////////////////////////////////////////////////////////////////////////
void SEdNode_NoiseGraphNode::Construct(const FArguments& InArgs, UEdNode_NoiseGraphNode* InNode)
{
	GraphNode = InNode;
	UpdateGraphNodeWithSeed(0);
	InNode->SEdNode = this;
}

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SEdNode_NoiseGraphNode::CreatePinWidgets()
{
	// Create Pin widgets for each of the pins.
	for( int32 PinIndex=0; PinIndex < GraphNode->Pins.Num(); ++PinIndex )
	{
		UEdGraphPin* CurPin = GraphNode->Pins[PinIndex];

		bool bHideNoConnectionPins = false;

		if (OwnerGraphPanelPtr.IsValid())
		{
			bHideNoConnectionPins = OwnerGraphPanelPtr.Pin()->GetPinVisibility() == SGraphEditor::Pin_HideNoConnection;
		}

		const bool bPinHasConections = CurPin->LinkedTo.Num() > 0;

		bool bPinDesiresToBeHidden = CurPin->bHidden || (bHideNoConnectionPins && !bPinHasConections); 

		if (!bPinDesiresToBeHidden)
		{
			TSharedPtr<SGraphPin> NewPin = CreatePinWidget(CurPin);
			check(NewPin.IsValid());

			// Assign an custom icon to not connectible pins
			if (CurPin->bNotConnectable)
			{
			}

			this->AddPin(NewPin.ToSharedRef());
		}
	}
}

void SEdNode_NoiseGraphNode::AddPin(const TSharedRef<SGraphPin>& PinToAdd)
{
	PinToAdd->SetOwner(SharedThis(this));

	const UEdGraphPin* PinObj = PinToAdd->GetPinObj();
	const bool bAdvancedParameter = PinObj && PinObj->bAdvancedView;
	if (bAdvancedParameter)
	{
		PinToAdd->SetVisibility( TAttribute<EVisibility>(PinToAdd, &SGraphPin::IsPinVisibleAsAdvanced) );
	}

	if (PinToAdd->GetDirection() == EEdGraphPinDirection::EGPD_Input)
	{
		FMargin Padding = Settings->GetInputPinPadding();
		Padding.Left *= 0.5f;
		Padding.Right = 0.0f;

		LeftNodeBox->AddSlot()
		.AutoHeight()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		.Padding(Padding)
		[
			PinToAdd
		];
		InputPins.Add(PinToAdd);
	}
	else // Direction == EEdGraphPinDirection::EGPD_Output
		{
		FMargin Padding = Settings->GetOutputPinPadding();
		Padding.Left = 0.0f;
		Padding.Right *= 0.5f;

		RightNodeBox->AddSlot()
		.AutoHeight()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		.Padding(Padding)
		[
			PinToAdd
		];
		OutputPins.Add(PinToAdd);
		}
}

void SEdNode_NoiseGraphNode::CreateBelowPinControls(TSharedPtr<SVerticalBox> MainBox)
{
	if (GraphNode && MainBox.IsValid())
	{
		// Count the number of visible input pins on the left
		int32 LeftPinCount = 0;
		if (GraphNode->AdvancedPinDisplay == ENodeAdvancedPins::Hidden)
		{
			// Advanced view pins are hidden so exclude them from the pin count
			for (int32 i = 0; i < InputPins.Num(); ++i)
			{
				const UEdGraphPin* PinObj = InputPins[i]->GetPinObj();
				if (!PinObj->bAdvancedView)
				{
					LeftPinCount++;
				}
			}
		}
		else
		{
			LeftPinCount = InputPins.Num();
		}

		int32 RightPinCount = OutputPins.Num();

		const float NegativeHPad = FMath::Max<float>(-Settings->PaddingTowardsNodeEdge, 0.0f);
		const float ExtraPad = 0.0f;

		// Place preview widget based on where the least pins are
		if ((LeftPinCount < RightPinCount) || (RightPinCount == 0))
		{
			LeftNodeBox->AddSlot()
			.Padding(FMargin(NegativeHPad + ExtraPad, 0.0f, 0.0f, 0.0f))
			.AutoHeight()
			.HAlign(HAlign_Left)
			[
				CreatePreviewWidget()
			];
		}
		else if (LeftPinCount > RightPinCount)
		{
			RightNodeBox->AddSlot()
			.Padding(FMargin(NegativeHPad + ExtraPad, 0.0f, 0.0f, 0.0f))
			.AutoHeight()
			.HAlign(HAlign_Right)
			[
				CreatePreviewWidget()
			];
		}
		else
		{
			MainBox->AddSlot()
			.Padding(Settings->GetNonPinNodeBodyPadding())
			.AutoHeight()
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				.AutoWidth()
				[
					CreatePreviewWidget()
				]
			];
		}
	}
}

TSharedRef<SWidget> SEdNode_NoiseGraphNode::CreatePreviewWidget()
{
	UEdNode_NoiseGraphNode* MyNode = CastChecked<UEdNode_NoiseGraphNode>(GraphNode);
	if (MyNode != nullptr && MyNode->NoiseGraphNode != nullptr && MyNode->NoiseGraphNode->GetShouldRenderPreview())
	{
		int Seed = UKismetMathLibrary::RandomInteger(100000);
		UpdateGraphNodeWithSeed(Seed, false);
		Brush.SetResourceObject(PreviewTexture);
		Brush.ImageSize = FVector2D(128, 128);
		return SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			.Padding(2)
			[
				MyNode->NoiseGraphNode->AddCustomSlateToNode()
			]

			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2)
			[
				SNew(SImage)
				.Image(&Brush)
			];
	}
	return MyNode->NoiseGraphNode->AddCustomSlateToNode();
}

bool SEdNode_NoiseGraphNode::IsNameReadOnly() const
{
	return true;
}

void SEdNode_NoiseGraphNode::AddReferencedObjects(FReferenceCollector& Collector)
{
	Collector.AddReferencedObject(PreviewTexture);
}

UTexture* SEdNode_NoiseGraphNode::GetOrInitPreviewTexture()
{
	if (PreviewTexture == nullptr)
	{
		PreviewTexture = UTexture2D::CreateTransient(64, 64, EPixelFormat::PF_R8G8B8A8);
		PreviewTexture->Filter = TextureFilter::TF_Nearest;
		PreviewTexture->LODGroup = TextureGroup::TEXTUREGROUP_Pixels2D;

		Cast<UEdGraph_NoiseGraph>(GraphNode->GetGraph())->PreviewTextureHolder.Add(PreviewTexture);
		PreviewTexture->UpdateResource();	
	}
	
	return PreviewTexture;
}


void SEdNode_NoiseGraphNode::UpdateGraphNodeWithSeed(int InSeed, bool bUpdateGraphNode)
{
	UEdNode_NoiseGraphNode* MyNode = CastChecked<UEdNode_NoiseGraphNode>(GraphNode);
	if (MyNode != nullptr && MyNode->NoiseGraphNode != nullptr && MyNode->NoiseGraphNode->GetShouldRenderPreview())
	{
		GetOrInitPreviewTexture();
		MyNode->NoiseGraphNode->RenderPreviewTexture(PreviewTexture, InSeed);
	}

	if (bUpdateGraphNode)
	{
		SGraphNode::UpdateGraphNode();
	}
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SEdNode_NoiseGraphNode::OnNameTextCommited(const FText& InText, ETextCommit::Type CommitInfo)
{
	SGraphNode::OnNameTextCommited(InText, CommitInfo);

	UEdNode_NoiseGraphNode* MyNode = CastChecked<UEdNode_NoiseGraphNode>(GraphNode);

	if (MyNode != nullptr && MyNode->NoiseGraphNode != nullptr)
	{
		const FScopedTransaction Transaction(LOCTEXT("NoiseGraphEditorRenameNode", "Noise Graph Editor: Rename Node"));
		MyNode->Modify();
		MyNode->NoiseGraphNode->Modify();
		MyNode->NoiseGraphNode->SetNodeTitle(InText);
		UpdateGraphNodeWithSeed(0);
	}
}

FSlateColor SEdNode_NoiseGraphNode::GetBorderBackgroundColor() const
{
	UEdNode_NoiseGraphNode* MyNode = CastChecked<UEdNode_NoiseGraphNode>(GraphNode);
	return MyNode ? MyNode->GetBackgroundColor() : NoiseGraphColors::NodeBorder::HighlightAbortRange0;
}

FSlateColor SEdNode_NoiseGraphNode::GetBackgroundColor() const
{
	return NoiseGraphColors::NodeBody::Default;
}

EVisibility SEdNode_NoiseGraphNode::GetDragOverMarkerVisibility() const
{
	return EVisibility::Visible;
}

const FSlateBrush* SEdNode_NoiseGraphNode::GetNameIcon() const
{
	return FAppStyle::GetBrush(TEXT("BTEditor.Graph.BTNode.Icon"));
}

#undef LOCTEXT_NAMESPACE
