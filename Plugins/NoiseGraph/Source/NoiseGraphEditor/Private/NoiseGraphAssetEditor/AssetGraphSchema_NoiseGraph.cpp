#include "NoiseGraphAssetEditor/AssetGraphSchema_NoiseGraph.h"

#include "BlueprintConnectionDrawingPolicy.h"
#include "ToolMenus.h"
#include "NoiseGraphEditorPCH.h"
#include "NoiseGraphAssetEditor/EdNode_NoiseGraphNode.h"
#include "NoiseGraphAssetEditor/EdNode_NoiseGraphEdge.h"
#include "NoiseGraphAssetEditor/ConnectionDrawingPolicy_NoiseGraph.h"
#include "GraphEditorActions.h"
#include "Framework/Commands/GenericCommands.h"
#include "Kismet/KismetMathLibrary.h"
#include "NoiseGraphAssetEditor/SEdNode_NoiseGraphNode.h"

#define LOCTEXT_NAMESPACE "AssetSchema_NoiseGraph"

int32 UAssetGraphSchema_NoiseGraph::CurrentCacheRefreshID = 0;

UEdGraphNode* FAssetSchemaAction_NoiseGraph_NewNode::PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode /*= true*/)
{
	UEdGraphNode* ResultNode = nullptr;

	if (NodeTemplate != nullptr)
	{
		const FScopedTransaction Transaction(LOCTEXT("NoiseGraphEditorNewNode", "Noise Graph Editor: New Node"));
		ParentGraph->Modify();
		if (FromPin != nullptr)
			FromPin->Modify();

		NodeTemplate->Rename(nullptr, ParentGraph);
		ParentGraph->AddNode(NodeTemplate, true, bSelectNewNode);

		NodeTemplate->CreateNewGuid();
		NodeTemplate->PostPlacedNewNode();
		NodeTemplate->AllocateDefaultPins();
		NodeTemplate->AutowireNewNode(FromPin);

		NodeTemplate->NodePosX = Location.X;
		NodeTemplate->NodePosY = Location.Y;

		NodeTemplate->NoiseGraphNode->SetFlags(RF_Transactional);
		NodeTemplate->SetFlags(RF_Transactional);

		ResultNode = NodeTemplate;
	}

	return ResultNode;
}

void FAssetSchemaAction_NoiseGraph_NewNode::AddReferencedObjects(FReferenceCollector& Collector)
{
	FEdGraphSchemaAction::AddReferencedObjects(Collector);
	Collector.AddReferencedObject(NodeTemplate);
}

UEdGraphNode* FAssetSchemaAction_NoiseGraph_NewEdge::PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode /*= true*/)
{
	UEdGraphNode* ResultNode = nullptr;

	if (NodeTemplate != nullptr)
	{
		const FScopedTransaction Transaction(LOCTEXT("NoiseGraphEditorNewEdge", "Noise Graph Editor: New Edge"));
		ParentGraph->Modify();
		if (FromPin != nullptr)
			FromPin->Modify();

		NodeTemplate->Rename(nullptr, ParentGraph);
		ParentGraph->AddNode(NodeTemplate, true, bSelectNewNode);

		NodeTemplate->CreateNewGuid();
		NodeTemplate->PostPlacedNewNode();
		NodeTemplate->AllocateDefaultPins();
		NodeTemplate->AutowireNewNode(FromPin);

		NodeTemplate->NodePosX = Location.X;
		NodeTemplate->NodePosY = Location.Y;

		NodeTemplate->NoiseGraphEdge->SetFlags(RF_Transactional);
		NodeTemplate->SetFlags(RF_Transactional);

		ResultNode = NodeTemplate;
	}
	
	return ResultNode;
}

void FAssetSchemaAction_NoiseGraph_NewEdge::AddReferencedObjects(FReferenceCollector& Collector)
{
	FEdGraphSchemaAction::AddReferencedObjects(Collector);
	Collector.AddReferencedObject(NodeTemplate);
}

void UAssetGraphSchema_NoiseGraph::GetBreakLinkToSubMenuActions(UToolMenu* Menu, UEdGraphPin* InGraphPin)
{
	// Make sure we have a unique name for every entry in the list
	TMap< FString, uint32 > LinkTitleCount;

	FToolMenuSection& Section = Menu->FindOrAddSection("NoiseGraphAssetGraphSchemaPinActions");

	// Add all the links we could break from
	for (TArray<class UEdGraphPin*>::TConstIterator Links(InGraphPin->LinkedTo); Links; ++Links)
	{
		UEdGraphPin* Pin = *Links;
		FString TitleString = Pin->GetOwningNode()->GetNodeTitle(ENodeTitleType::ListView).ToString();
		FText Title = FText::FromString(TitleString);
		if (Pin->PinName != TEXT(""))
		{
			TitleString = FString::Printf(TEXT("%s (%s)"), *TitleString, *Pin->PinName.ToString());

			// Add name of connection if possible
			FFormatNamedArguments Args;
			Args.Add(TEXT("NodeTitle"), Title);
			Args.Add(TEXT("PinName"), Pin->GetDisplayName());
			Title = FText::Format(LOCTEXT("BreakDescPin", "{NodeTitle} ({PinName})"), Args);
		}

		uint32& Count = LinkTitleCount.FindOrAdd(TitleString);

		FText Description;
		FFormatNamedArguments Args;
		Args.Add(TEXT("NodeTitle"), Title);
		Args.Add(TEXT("NumberOfNodes"), Count);

		if (Count == 0)
		{
			Description = FText::Format(LOCTEXT("BreakDesc", "Break link to {NodeTitle}"), Args);
		}
		else
		{
			Description = FText::Format(LOCTEXT("BreakDescMulti", "Break link to {NodeTitle} ({NumberOfNodes})"), Args);
		}
		++Count;

		Section.AddMenuEntry(NAME_None, Description, Description, FSlateIcon(), FUIAction(
			FExecuteAction::CreateUObject(this, &UAssetGraphSchema_NoiseGraph::BreakSinglePinLink, const_cast<UEdGraphPin*>(InGraphPin), *Links)));
	}
}

EGraphType UAssetGraphSchema_NoiseGraph::GetGraphType(const UEdGraph* TestEdGraph) const
{
	return GT_Macro;
}

void UAssetGraphSchema_NoiseGraph::GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const
{
	UNoiseGraph* Graph = CastChecked<UNoiseGraph>(ContextMenuBuilder.CurrentGraph->GetOuter());

	if (Graph->NodeType == nullptr)
	{
		return;
	}

	const bool bNoParent = (ContextMenuBuilder.FromPin == NULL);

	const FText AddToolTip = LOCTEXT("NewNoiseGraphNodeTooltip", "Add node here");

	TSet<TSubclassOf<UNoiseGraphNode> > Visited;

	FText Desc = Graph->NodeType.GetDefaultObject()->ContextMenuName;

	if (Desc.IsEmpty())
	{
		FString Title = Graph->NodeType->GetName();
		Title.RemoveFromEnd("_C");
		Desc = FText::FromString(Title);
	}

	if (!Graph->NodeType->HasAnyClassFlags(CLASS_Abstract))
	{
		TSharedPtr<FAssetSchemaAction_NoiseGraph_NewNode> NewNodeAction(new FAssetSchemaAction_NoiseGraph_NewNode(LOCTEXT("NoiseGraphNodeAction", "Noise Graph Node"), Desc, AddToolTip, 0));
		NewNodeAction->NodeTemplate = NewObject<UEdNode_NoiseGraphNode>(ContextMenuBuilder.OwnerOfTemporaries);
		NewNodeAction->NodeTemplate->NoiseGraphNode = NewObject<UNoiseGraphNode>(NewNodeAction->NodeTemplate, Graph->NodeType);
		NewNodeAction->NodeTemplate->NoiseGraphNode->Graph = Graph;
		ContextMenuBuilder.AddAction(NewNodeAction);

		Visited.Add(Graph->NodeType);
	}

	for (TObjectIterator<UClass> It; It; ++It)
	{
		if (It->IsChildOf(Graph->NodeType) && !It->HasAnyClassFlags(CLASS_Abstract) && !Visited.Contains(*It))
		{
			TSubclassOf<UNoiseGraphNode> NodeType = *It;

			if (It->GetName().StartsWith("REINST") || It->GetName().StartsWith("SKEL"))
				continue;

			if (!Graph->GetClass()->IsChildOf(NodeType.GetDefaultObject()->CompatibleGraphType))
				continue;

			Desc = NodeType.GetDefaultObject()->ContextMenuName;

			if (Desc.IsEmpty())
			{
				FString Title = NodeType->GetName();
				Title.RemoveFromEnd("_C");
				Desc = FText::FromString(Title);
			}

			TSharedPtr<FAssetSchemaAction_NoiseGraph_NewNode> Action(new FAssetSchemaAction_NoiseGraph_NewNode(LOCTEXT("NoiseGraphNodeAction", "Noise Graph Node"), Desc, AddToolTip, 0));
			Action->NodeTemplate = NewObject<UEdNode_NoiseGraphNode>(ContextMenuBuilder.OwnerOfTemporaries);
			Action->NodeTemplate->NoiseGraphNode = NewObject<UNoiseGraphNode>(Action->NodeTemplate, NodeType);
			Action->NodeTemplate->NoiseGraphNode->Graph = Graph;
			ContextMenuBuilder.AddAction(Action);

			Visited.Add(NodeType);
		}
	}
}

void UAssetGraphSchema_NoiseGraph::GetContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
	if (Context->Pin)
	{
		{
			FToolMenuSection& Section = Menu->AddSection("NoiseGraphAssetGraphSchemaNodeActions", LOCTEXT("PinActionsMenuHeader", "Pin Actions"));
			// Only display the 'Break Links' option if there is a link to break!
			if (Context->Pin->LinkedTo.Num() > 0)
			{
				Section.AddMenuEntry(FGraphEditorCommands::Get().BreakPinLinks);

				// add sub menu for break link to
				if (Context->Pin->LinkedTo.Num() > 1)
				{
					Section.AddSubMenu(
						"BreakLinkTo",
						LOCTEXT("BreakLinkTo", "Break Link To..."),
						LOCTEXT("BreakSpecificLinks", "Break a specific link..."),
						FNewToolMenuDelegate::CreateUObject((UAssetGraphSchema_NoiseGraph* const)this, &UAssetGraphSchema_NoiseGraph::GetBreakLinkToSubMenuActions, const_cast<UEdGraphPin*>(Context->Pin)));
				}
				else
				{
					((UAssetGraphSchema_NoiseGraph* const)this)->GetBreakLinkToSubMenuActions(Menu, const_cast<UEdGraphPin*>(Context->Pin));
				}
			}
		}
	}
	else if (Context->Node)
	{
		{
			FToolMenuSection& Section = Menu->AddSection("NoiseGraphAssetGraphSchemaNodeActions", LOCTEXT("ClassActionsMenuHeader", "Node Actions"));
			Section.AddMenuEntry(FGenericCommands::Get().Delete);
			Section.AddMenuEntry(FGenericCommands::Get().Cut);
			Section.AddMenuEntry(FGenericCommands::Get().Copy);
			Section.AddMenuEntry(FGenericCommands::Get().Duplicate);

			Section.AddMenuEntry(FGraphEditorCommands::Get().BreakNodeLinks);
		}
	}

	Super::GetContextMenuActions(Menu, Context);
}

const FPinConnectionResponse UAssetGraphSchema_NoiseGraph::CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const
{
	// Make sure the pins are not on the same node
	if (A->GetOwningNode() == B->GetOwningNode())
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, LOCTEXT("PinErrorSameNode", "Can't connect node to itself"));
	}

	const UEdGraphPin *Out = A;
	const UEdGraphPin *In = B;

	UEdNode_NoiseGraphNode* EdNode_Out = Cast<UEdNode_NoiseGraphNode>(Out->GetOwningNode());
	UEdNode_NoiseGraphNode* EdNode_In = Cast<UEdNode_NoiseGraphNode>(In->GetOwningNode());

	if (EdNode_Out == nullptr || EdNode_In == nullptr)
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, LOCTEXT("PinError", "Not a valid UNoiseGraphEdNode"));
	}

	if (Out->LinkedTo.Num() > 0)
	{
		//return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_A, LOCTEXT("PinConnectReplace", "Replace connection"));
	}

	/*
	FText ErrorMessage;
	if (!EdNode_Out->NoiseGraphNode->CanCreateConnectionTo(EdNode_In->NoiseGraphNode, EdNode_Out->GetOutputPin()->LinkedTo.Num(), ErrorMessage))
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, ErrorMessage);
	}
	if (!EdNode_In->NoiseGraphNode->CanCreateConnectionFrom(EdNode_Out->NoiseGraphNode, EdNode_In->GetInputPin()->LinkedTo.Num(), ErrorMessage))
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, ErrorMessage);
	}*/

	if (EdNode_Out->NoiseGraphNode->GetGraph()->bEdgeEnabled)
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_MAKE_WITH_CONVERSION_NODE, LOCTEXT("PinConnect", "Connect nodes with edge"));
	}
	else
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_MAKE, LOCTEXT("PinConnect", "Connect nodes"));
	}
}

bool UAssetGraphSchema_NoiseGraph::TryCreateConnection(UEdGraphPin* A, UEdGraphPin* B) const
{
	return Super::TryCreateConnection(A, B);
}

bool UAssetGraphSchema_NoiseGraph::CreateAutomaticConversionNodeAndConnections(UEdGraphPin* A, UEdGraphPin* B) const
{
	UEdNode_NoiseGraphNode* NodeA = Cast<UEdNode_NoiseGraphNode>(A->GetOwningNode());
	UEdNode_NoiseGraphNode* NodeB = Cast<UEdNode_NoiseGraphNode>(B->GetOwningNode());

	// Are nodes and pins all valid?
	if (!NodeA)
		return false;
	
	UNoiseGraph* Graph = NodeA->NoiseGraphNode->GetGraph();

	FVector2D InitPos((NodeA->NodePosX + NodeB->NodePosX) / 2, (NodeA->NodePosY + NodeB->NodePosY) / 2);

	FAssetSchemaAction_NoiseGraph_NewEdge Action;
	Action.NodeTemplate = NewObject<UEdNode_NoiseGraphEdge>(NodeA->GetGraph());
	Action.NodeTemplate->SetEdge(NewObject<UNoiseGraphEdge>(Action.NodeTemplate, Graph->EdgeType));
	UEdNode_NoiseGraphEdge* EdgeNode = Cast<UEdNode_NoiseGraphEdge>(Action.PerformAction(NodeA->GetGraph(), nullptr, InitPos, false));

	if (A->Direction == EGPD_Input && B->Direction == EGPD_Output)
	{
		EdgeNode->CreateConnections(B, A);
	}
	else
	{
		EdgeNode->CreateConnections(A, B);
	}

	return true;
}

class FConnectionDrawingPolicy* UAssetGraphSchema_NoiseGraph::CreateConnectionDrawingPolicy(int32 InBackLayerID, int32 InFrontLayerID, float InZoomFactor, const FSlateRect& InClippingRect, class FSlateWindowElementList& InDrawElements, class UEdGraph* InGraphObj) const
{
	return new FConnectionDrawingPolicy_NoiseGraph(InBackLayerID, InFrontLayerID, InZoomFactor, InClippingRect, InDrawElements, InGraphObj);
}

FLinearColor UAssetGraphSchema_NoiseGraph::GetPinTypeColor(const FEdGraphPinType& PinType) const
{
	return FColor::White;
}

void UAssetGraphSchema_NoiseGraph::BreakNodeLinks(UEdGraphNode& TargetNode) const
{
	const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "GraphEd_BreakNodeLinks", "Break Node Links"));

	Super::BreakNodeLinks(TargetNode);
}

void UAssetGraphSchema_NoiseGraph::BreakPinLinks(UEdGraphPin& TargetPin, bool bSendsNodeNotifcation) const
{
	const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "GraphEd_BreakPinLinks", "Break Pin Links"));

	Super::BreakPinLinks(TargetPin, bSendsNodeNotifcation);
}

void UAssetGraphSchema_NoiseGraph::BreakSinglePinLink(UEdGraphPin* SourcePin, UEdGraphPin* TargetPin) const
{
	const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "GraphEd_BreakSinglePinLink", "Break Pin Link"));

	Super::BreakSinglePinLink(SourcePin, TargetPin);
}

UEdGraphPin* UAssetGraphSchema_NoiseGraph::DropPinOnNode(UEdGraphNode* InTargetNode, const FName& InSourcePinName, const FEdGraphPinType& InSourcePinType, EEdGraphPinDirection InSourcePinDirection) const
{
	return nullptr;
}

bool UAssetGraphSchema_NoiseGraph::SupportsDropPinOnNode(UEdGraphNode* InTargetNode, const FEdGraphPinType& InSourcePinType, EEdGraphPinDirection InSourcePinDirection, FText& OutErrorMessage) const
{
	return Cast<UEdNode_NoiseGraphNode>(InTargetNode) != nullptr;
}

bool UAssetGraphSchema_NoiseGraph::IsCacheVisualizationOutOfDate(int32 InVisualizationCacheID) const
{
	return CurrentCacheRefreshID != InVisualizationCacheID;
}

int32 UAssetGraphSchema_NoiseGraph::GetCurrentVisualizationCacheID() const
{
	return CurrentCacheRefreshID;
}

void UAssetGraphSchema_NoiseGraph::ForceVisualizationCacheClear() const
{
	++CurrentCacheRefreshID;
}

#undef LOCTEXT_NAMESPACE
