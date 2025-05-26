#include "NoiseGraphAssetEditor/ConnectionDrawingPolicy_NoiseGraph.h"
#include "NoiseGraphAssetEditor/EdNode_NoiseGraphNode.h"
#include "NoiseGraphAssetEditor/EdNode_NoiseGraphEdge.h"

FConnectionDrawingPolicy_NoiseGraph::FConnectionDrawingPolicy_NoiseGraph(int32 InBackLayerID, int32 InFrontLayerID, float ZoomFactor, const FSlateRect& InClippingRect, FSlateWindowElementList& InDrawElements, UEdGraph* InGraphObj)
	: FConnectionDrawingPolicy(InBackLayerID, InFrontLayerID, ZoomFactor, InClippingRect, InDrawElements)
	, GraphObj(InGraphObj)
{
}

void FConnectionDrawingPolicy_NoiseGraph::DetermineWiringStyle(UEdGraphPin* OutputPin, UEdGraphPin* InputPin, /*inout*/ FConnectionParams& Params)
{
	Params.AssociatedPin1 = OutputPin;
	Params.AssociatedPin2 = InputPin;
	Params.WireThickness = 1.5f;

	const bool bDeemphasizeUnhoveredPins = HoveredPins.Num() > 0;
	if (bDeemphasizeUnhoveredPins)
	{
		ApplyHoverDeemphasis(OutputPin, InputPin, /*inout*/ Params.WireThickness, /*inout*/ Params.WireColor);
	}
}

void FConnectionDrawingPolicy_NoiseGraph::Draw(TMap<TSharedRef<SWidget>, FArrangedWidget>& InPinGeometries, FArrangedChildren& ArrangedNodes)
{
	// Build an acceleration structure to quickly find geometry for the nodes
	NodeWidgetMap.Empty();
	for (int32 NodeIndex = 0; NodeIndex < ArrangedNodes.Num(); ++NodeIndex)
	{
		FArrangedWidget& CurWidget = ArrangedNodes[NodeIndex];
		TSharedRef<SGraphNode> ChildNode = StaticCastSharedRef<SGraphNode>(CurWidget.Widget);
		NodeWidgetMap.Add(ChildNode->GetNodeObj(), NodeIndex);
	}

	// Now draw
	FConnectionDrawingPolicy::Draw(InPinGeometries, ArrangedNodes);
}

void FConnectionDrawingPolicy_NoiseGraph::DrawPreviewConnector(const FGeometry& PinGeometry, const FVector2D& StartPoint, const FVector2D& EndPoint, UEdGraphPin* Pin)
{
	FConnectionParams Params;
	DetermineWiringStyle(Pin, nullptr, /*inout*/ Params);

	DrawSplineWithArrow(StartPoint, EndPoint, Params);
}

void FConnectionDrawingPolicy_NoiseGraph::DrawSplineWithArrow(const FVector2D& StartAnchorPoint, const FVector2D& EndAnchorPoint, const FConnectionParams& Params)
{
	FConnectionDrawingPolicy::DrawSplineWithArrow(StartAnchorPoint, EndAnchorPoint, Params);
}

void FConnectionDrawingPolicy_NoiseGraph::Internal_DrawLineWithArrow(const FVector2D& StartAnchorPoint, const FVector2D& EndAnchorPoint, const FConnectionParams& Params)
{
	//@TODO: Should this be scaled by zoom factor?
	const float LineSeparationAmount = 4.5f;

	const FVector2D DeltaPos = EndAnchorPoint - StartAnchorPoint;
	const FVector2D UnitDelta = DeltaPos.GetSafeNormal();
	const FVector2D Normal = FVector2D(DeltaPos.Y, -DeltaPos.X).GetSafeNormal();

	// Come up with the final start/end points
	const FVector2D DirectionBias = Normal * LineSeparationAmount;
	const FVector2D LengthBias = ArrowRadius.X * UnitDelta;
	const FVector2D StartPoint = StartAnchorPoint + DirectionBias + LengthBias;
	const FVector2D EndPoint = EndAnchorPoint + DirectionBias - LengthBias;

	// Draw a line/spline
	DrawConnection(WireLayerID, StartPoint, EndPoint, Params);

	// Draw the arrow
	const FVector2D ArrowDrawPos = EndPoint - ArrowRadius;
	const float AngleInRadians = FMath::Atan2(DeltaPos.Y, DeltaPos.X);

	FSlateDrawElement::MakeRotatedBox(
		DrawElementsList,
		ArrowLayerID,
		FPaintGeometry(ArrowDrawPos, ArrowImage->ImageSize * ZoomFactor, ZoomFactor),
		ArrowImage,
		ESlateDrawEffect::None,
		AngleInRadians,
		TOptional<FVector2D>(),
		FSlateDrawElement::RelativeToElement,
		Params.WireColor
	);
}

void FConnectionDrawingPolicy_NoiseGraph::DrawSplineWithArrow(const FGeometry& StartGeom, const FGeometry& EndGeom, const FConnectionParams& Params)
{
	FConnectionDrawingPolicy::DrawSplineWithArrow(StartGeom, EndGeom, Params);
}

FVector2D FConnectionDrawingPolicy_NoiseGraph::ComputeSplineTangent(const FVector2D& Start, const FVector2D& End) const
{
	return FConnectionDrawingPolicy::ComputeSplineTangent(Start, End);
}

void FConnectionDrawingPolicy_NoiseGraph::DetermineLinkGeometry(FArrangedChildren& ArrangedNodes, TSharedRef<SWidget>& OutputPinWidget,
	UEdGraphPin* OutputPin, UEdGraphPin* InputPin, FArrangedWidget*& StartWidgetGeometry, FArrangedWidget*& EndWidgetGeometry)
{
	if (UEdNode_NoiseGraphEdge* EdgeNode = Cast<UEdNode_NoiseGraphEdge>(InputPin->GetOwningNode()))
	{
		if (EdgeNode->Pins[1]->LinkedTo.Num() > 0)
		{
			StartWidgetGeometry = PinGeometries->Find(OutputPinWidget);

			if (TSharedPtr<SGraphPin>* pTargetWidget = PinToPinWidgetMap.Find(EdgeNode->Pins[1]->LinkedTo[0]))
			{
				TSharedRef<SGraphPin> InputWidget = (*pTargetWidget).ToSharedRef();
				EndWidgetGeometry = PinGeometries->Find(InputWidget);
			}
		}
		else
		{
			UEdNode_NoiseGraphNode* Start = EdgeNode->GetStartNode();
			UEdNode_NoiseGraphNode* End = EdgeNode->GetEndNode();
			if (Start != nullptr && End != nullptr)
			{
				int32* StartNodeIndex = NodeWidgetMap.Find(Start);
				int32* EndNodeIndex = NodeWidgetMap.Find(End);
				if (StartNodeIndex != nullptr && EndNodeIndex != nullptr)
				{
					StartWidgetGeometry = &(ArrangedNodes[*StartNodeIndex]);
					EndWidgetGeometry = &(ArrangedNodes[*EndNodeIndex]);
				}
			}
		}
	}
	else
	{
		StartWidgetGeometry = PinGeometries->Find(OutputPinWidget);

		if (TSharedPtr<SGraphPin>* pTargetWidget = PinToPinWidgetMap.Find(InputPin))
		{
			TSharedRef<SGraphPin> InputWidget = (*pTargetWidget).ToSharedRef();
			EndWidgetGeometry = PinGeometries->Find(InputWidget);
		}
	}
}

