#pragma once

#include "CoreMinimal.h"
#include "NoiseGraphEdge.generated.h"

class UNoiseGraphNode;
class UNoiseGraph;

UCLASS(Blueprintable)
class NOISEGRAPHRUNTIME_API UNoiseGraphEdge : public UObject
{
	GENERATED_BODY()

public:
	UNoiseGraphEdge();
	virtual ~UNoiseGraphEdge();

	UPROPERTY(VisibleAnywhere, Category = "NoiseGraphNode")
	UNoiseGraph* Graph;

	UPROPERTY(BlueprintReadOnly, Category = "NoiseGraphEdge")
	UNoiseGraphNode* StartNode;

	UPROPERTY(BlueprintReadOnly, Category = "NoiseGraphEdge")
	UNoiseGraphNode* EndNode;

	UFUNCTION(BlueprintPure, Category = "NoiseGraphEdge")
	UNoiseGraph* GetGraph() const;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category = "NoiseGraphNode_Editor")
	bool bShouldDrawTitle = false;

	UPROPERTY(EditDefaultsOnly, Category = "NoiseGraphNode_Editor")
	FText NodeTitle;

	UPROPERTY(EditDefaultsOnly, Category = "NoiseGraphEdge")
	FLinearColor EdgeColour = FLinearColor(0.9f, 0.9f, 0.9f, 1.0f);
#endif

#if WITH_EDITOR
	virtual FText GetNodeTitle() const { return NodeTitle; }
	FLinearColor GetEdgeColour() { return EdgeColour; }

	virtual void SetNodeTitle(const FText& NewTitle);
#endif
	
};
