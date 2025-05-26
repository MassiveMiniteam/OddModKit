#include "NoiseGraphAssetEditor/EdNode_NoiseGraphEdge.h"
#include "NoiseGraphEdge.h"
#include "NoiseGraphAssetEditor/EdNode_NoiseGraphNode.h"

#define LOCTEXT_NAMESPACE "EdNode_NoiseGraphEdge"

UEdNode_NoiseGraphEdge::UEdNode_NoiseGraphEdge()
{
	bCanRenameNode = true;
}

void UEdNode_NoiseGraphEdge::SetEdge(UNoiseGraphEdge* Edge)
{
	NoiseGraphEdge = Edge;
}

void UEdNode_NoiseGraphEdge::AllocateDefaultPins()
{
	UEdGraphPin* Inputs = CreatePin(EGPD_Input, TEXT("Edge"), FName(), TEXT("In"));
	UEdGraphPin* Outputs = CreatePin(EGPD_Output, TEXT("Edge"), FName(), TEXT("Out"));
}

FText UEdNode_NoiseGraphEdge::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	if (NoiseGraphEdge)
	{
		return NoiseGraphEdge->GetNodeTitle();
	}
	return FText();
}

void UEdNode_NoiseGraphEdge::PinConnectionListChanged(UEdGraphPin* Pin)
{
	if (Pin->LinkedTo.Num() == 0)
	{
		// Commit suicide; transitions must always have an input and output connection
		Modify();

		// Our parent graph will have our graph in SubGraphs so needs to be modified to record that.
		if (UEdGraph* ParentGraph = GetGraph())
		{
			ParentGraph->Modify();
		}

		DestroyNode();
	}
}

void UEdNode_NoiseGraphEdge::PrepareForCopying()
{
	NoiseGraphEdge->Rename(nullptr, this, REN_DontCreateRedirectors | REN_DoNotDirty);
}

void UEdNode_NoiseGraphEdge::CreateConnections(UEdGraphPin* Start, UEdGraphPin* End)
{
	Pins[0]->Modify();
	Pins[0]->LinkedTo.Empty();

	Start->Modify();
	Pins[0]->MakeLinkTo(Start);

	// This to next
	Pins[1]->Modify();
	Pins[1]->LinkedTo.Empty();

	End->Modify();
	Pins[1]->MakeLinkTo(End);
}

UEdNode_NoiseGraphNode* UEdNode_NoiseGraphEdge::GetStartNode()
{
	if (Pins[0]->LinkedTo.Num() > 0)
	{
		return Cast<UEdNode_NoiseGraphNode>(Pins[0]->LinkedTo[0]->GetOwningNode());
	}
	else
	{
		return nullptr;
	}
}

UEdNode_NoiseGraphNode* UEdNode_NoiseGraphEdge::GetEndNode()
{
	if (Pins[1]->LinkedTo.Num() > 0)
	{
		return Cast<UEdNode_NoiseGraphNode>(Pins[1]->LinkedTo[0]->GetOwningNode());
	}
	else
	{
		return nullptr;
	}
}

#undef LOCTEXT_NAMESPACE

