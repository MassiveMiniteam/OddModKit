#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"
#include "NoiseGraphNode.h"
#include "EdNode_NoiseGraphNode.generated.h"

class UEdNode_NoiseGraphEdge;
class UEdGraph_NoiseGraph;
class SEdNode_NoiseGraphNode;

UCLASS(MinimalAPI)
class UEdNode_NoiseGraphNode : public UEdGraphNode
{
	GENERATED_BODY()

public:
	UEdNode_NoiseGraphNode();
	virtual ~UEdNode_NoiseGraphNode();

	UPROPERTY(VisibleAnywhere, Instanced, Category = "NoiseGraph")
	UNoiseGraphNode* NoiseGraphNode;

	void SetNoiseGraphNode(UNoiseGraphNode* InNode);
	UEdGraph_NoiseGraph* GetNoiseGraphEdGraph();

	SEdNode_NoiseGraphNode* SEdNode;

	virtual void AllocateDefaultPins() override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual void PrepareForCopying() override;
	virtual void AutowireNewNode(UEdGraphPin* FromPin) override;

	virtual FLinearColor GetBackgroundColor() const;

#if WITH_EDITOR
	virtual void PostEditUndo() override;
#endif

};
