#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraph.h"
#include "EdGraph_NoiseGraph.generated.h"

class UNoiseGraph;
class UNoiseGraphNode;
class UNoiseGraphEdge;
class UEdNode_NoiseGraphNode;
class UEdNode_NoiseGraphEdge;

UCLASS()
class NOISEGRAPHEDITOR_API UEdGraph_NoiseGraph : public UEdGraph
{
	GENERATED_BODY()

public:
	UEdGraph_NoiseGraph();
	virtual ~UEdGraph_NoiseGraph();

	virtual void RebuildNoiseGraph();

	UNoiseGraph* GetNoiseGraph() const;

	virtual bool Modify(bool bAlwaysMarkDirty = true) override;
	virtual void PostEditUndo() override;

	UPROPERTY(Transient)
	TMap<UNoiseGraphNode*, UEdNode_NoiseGraphNode*> NodeMap;

	UPROPERTY(Transient)
	TMap<UNoiseGraphEdge*, UEdNode_NoiseGraphEdge*> EdgeMap;

	// avoids garbage collection
	UPROPERTY(Transient)
	TArray<UTexture2D*> PreviewTextureHolder;

protected:
	void Clear();

	void SortNodes(UNoiseGraphNode* RootNode);
};
