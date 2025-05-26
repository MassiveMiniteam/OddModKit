#include "NoiseGraphAssetEditor/EdNode_NoiseGraphNode.h"

#include "Kismet/KismetMathLibrary.h"
#include "NoiseGraphAssetEditor/EdGraph_NoiseGraph.h"
#include "Kismet2/Kismet2NameValidators.h"
#include "Kismet2/BlueprintEditorUtils.h"

#define LOCTEXT_NAMESPACE "EdNode_NoiseGraph"

UEdNode_NoiseGraphNode::UEdNode_NoiseGraphNode()
{
	bCanRenameNode = true;
}

UEdNode_NoiseGraphNode::~UEdNode_NoiseGraphNode()
{

}

void UEdNode_NoiseGraphNode::AllocateDefaultPins()
{
	for (int i = 0; i < NoiseGraphNode->GetInputs().Num(); i++)
	{
		CreatePin(EGPD_Input, "MultipleNodes", FName(), *NoiseGraphNode->GetInputs()[i]);
	}
	
	for (int i = 0; i < NoiseGraphNode->GetOutputs().Num(); i++)
	{
		CreatePin(EGPD_Output, "MultipleNodes", FName(), *NoiseGraphNode->GetOutputs()[i]);
	}
}

UEdGraph_NoiseGraph* UEdNode_NoiseGraphNode::GetNoiseGraphEdGraph()
{
	return Cast<UEdGraph_NoiseGraph>(GetGraph());
}

FText UEdNode_NoiseGraphNode::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	if (NoiseGraphNode == nullptr)
	{
		return Super::GetNodeTitle(TitleType);
	}
	else
	{
		return NoiseGraphNode->GetNodeTitle();
	}
}

void UEdNode_NoiseGraphNode::PrepareForCopying()
{
	NoiseGraphNode->Rename(nullptr, this, REN_DontCreateRedirectors | REN_DoNotDirty);
}

void UEdNode_NoiseGraphNode::AutowireNewNode(UEdGraphPin* FromPin)
{
	Super::AutowireNewNode(FromPin);
}

void UEdNode_NoiseGraphNode::SetNoiseGraphNode(UNoiseGraphNode* InNode)
{
	NoiseGraphNode = InNode;
}

FLinearColor UEdNode_NoiseGraphNode::GetBackgroundColor() const
{
	return NoiseGraphNode == nullptr ? FLinearColor::Black : NoiseGraphNode->GetBackgroundColor();
}

void UEdNode_NoiseGraphNode::PostEditUndo()
{
	UEdGraphNode::PostEditUndo();
}

#undef LOCTEXT_NAMESPACE
