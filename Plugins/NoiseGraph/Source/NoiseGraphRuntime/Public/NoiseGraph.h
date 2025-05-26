#pragma once

#include "CoreMinimal.h"
#include "NoiseGraphNode.h"
#include "NoiseGraphEdge.h"
#include "GameplayTagContainer.h"
#include "Curves/CurveVector.h"
#include "NoiseGraph.generated.h"

class UEdGraph;

UCLASS(Blueprintable)
class NOISEGRAPHRUNTIME_API UNoiseGraph : public UObject
{
	GENERATED_BODY()

public:
	UNoiseGraph();
	virtual ~UNoiseGraph();

	UPROPERTY(EditDefaultsOnly, Category = "NoiseGraph")
	FString Name;

	UPROPERTY(EditDefaultsOnly, Category = "NoiseGraph")
	TSubclassOf<UNoiseGraphNode> NodeType;

	UPROPERTY(EditDefaultsOnly, Category = "NoiseGraph")
	TSubclassOf<UNoiseGraphEdge> EdgeType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NoiseGraph")
	FGameplayTagContainer GraphTags;

	UPROPERTY(BlueprintReadOnly, Category = "NoiseGraph")
	TArray<UNoiseGraphNode*> RootNodes;

	UPROPERTY(BlueprintReadOnly, Category = "NoiseGraph")
	TArray<UNoiseGraphNode*> AllNodes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NoiseGraph")
	bool bEdgeEnabled;

	UFUNCTION(BlueprintCallable, Category = "NoiseGraph")
	void Print(bool ToConsole = true, bool ToScreen = true);

	UFUNCTION(BlueprintCallable, Category = "NoiseGraph")
	int GetLevelNum() const;

	UFUNCTION(BlueprintCallable, Category = "NoiseGraph")
	void GetNodesByLevel(int Level, TArray<UNoiseGraphNode*>& Nodes);

	void ClearGraph();

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UEdGraph> EdGraph;

	UPROPERTY(EditDefaultsOnly, Category = "NoiseGraph_Editor")
	bool bCanRenameNode;
#endif
};
