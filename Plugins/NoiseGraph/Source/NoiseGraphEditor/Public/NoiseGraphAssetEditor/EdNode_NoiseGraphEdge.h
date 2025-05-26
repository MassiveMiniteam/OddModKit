#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"
#include "EdNode_NoiseGraphEdge.generated.h"

class UNoiseGraphNode;
class UNoiseGraphEdge;
class UEdNode_NoiseGraphNode;

UCLASS(MinimalAPI)
class UEdNode_NoiseGraphEdge : public UEdGraphNode
{
	GENERATED_BODY()

public:
	UEdNode_NoiseGraphEdge();

	UPROPERTY()
	class UEdGraph* Graph;

	UPROPERTY(VisibleAnywhere, Instanced, Category = "NoiseGraph")
	UNoiseGraphEdge* NoiseGraphEdge;

	void SetEdge(UNoiseGraphEdge* Edge);

	virtual void AllocateDefaultPins() override;

	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;

	virtual void PinConnectionListChanged(UEdGraphPin* Pin) override;

	virtual void PrepareForCopying() override;

	virtual UEdGraphPin* GetInputPin() const { return Pins[0]; }
	virtual UEdGraphPin* GetOutputPin() const { return Pins[1]; }

	void CreateConnections(UEdGraphPin* Start, UEdGraphPin* End);

	UEdNode_NoiseGraphNode* GetStartNode();
	UEdNode_NoiseGraphNode* GetEndNode();
};
