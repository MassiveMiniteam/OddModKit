#pragma once

#include "CoreMinimal.h"
#include "NoiseGraphEdge.h"
#include "NoiseModule.h"
#include "Templates/SubclassOf.h"
#include "NoiseGraphNode.generated.h"

class UNoiseGraph;
class UNoiseGraphEdge;

UENUM(BlueprintType)
enum class ENodeLimit : uint8
{
	Unlimited,
    Limited
};


UCLASS(Blueprintable, Abstract)
class NOISEGRAPHRUNTIME_API UNoiseGraphNode : public UObject
{
	GENERATED_BODY()

public:
	UNoiseGraphNode();
	virtual ~UNoiseGraphNode();

	UPROPERTY(VisibleDefaultsOnly, Category = "NoiseGraphNode")
	UNoiseGraph* Graph;

	UPROPERTY(BlueprintReadOnly, Category = "NoiseGraphNode")
	TArray<UNoiseGraphNode*> ParentNodes;

	UPROPERTY(BlueprintReadOnly, Category = "NoiseGraphNode")
	TArray<UNoiseGraphNode*> ChildrenNodes;

	UPROPERTY(BlueprintReadOnly, Category = "NoiseGraphNode")
	TArray<UNoiseGraphEdge*> Edges;

	virtual bool GetShouldRenderPreview() const { return true; }

	virtual UNoiseModule* GetNoiseModule(int32 InSeed)
	{
		return nullptr;
	}

	UNoiseModule* GetNoiseAt(int Index, int32 InSeed)
	{
		if (Edges.Num() <= Index || Edges[Index] == nullptr || Edges[Index]->StartNode == nullptr)
		{
			return nullptr;
		}
		
		return Edges[Index]->StartNode->GetNoiseModule(InSeed);
	}

	void RenderPreviewTexture(UTexture2D* Texture2D, int Seed);
	virtual void OnRenderPreviewTexturePixel(UNoiseModule* Noise, int X, int Y, int InSeed, FLinearColor& Color) {}
	virtual TSharedRef<SWidget> AddCustomSlateToNode() { return SNullWidget::NullWidget; };
	
	UFUNCTION(BlueprintCallable, Category = "NoiseGraphNode")
	bool IsLeafNode() const;

	UFUNCTION(BlueprintCallable, Category = "NoiseGraphNode")
	UNoiseGraph* GetGraph() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "NoiseGraphNode")
	FText GetDescription() const;
	virtual FText GetDescription_Implementation() const;

	virtual TArray<FString> GetInputs() const { return TArray<FString>(); }

	virtual TArray<FString> GetOutputs() const { return { TEXT("Out") }; }

	//////////////////////////////////////////////////////////////////////////
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category = "NoiseGraphNode_Editor")
	FText NodeTitle;

	UPROPERTY(VisibleDefaultsOnly, Category = "NoiseGraphNode_Editor")
	TSubclassOf<UNoiseGraph> CompatibleGraphType;

	UPROPERTY(EditDefaultsOnly, Category = "NoiseGraphNode_Editor")
	FLinearColor BackgroundColor;

	UPROPERTY(EditDefaultsOnly, Category = "NoiseGraphNode_Editor")
	FText ContextMenuName;

	UPROPERTY(EditDefaultsOnly, Category = "NoiseGraphNode_Editor")
	ENodeLimit ParentLimitType;

	UPROPERTY(EditDefaultsOnly, Category = "NoiseGraphNode_Editor" ,meta = (ClampMin = "0",EditCondition = "ParentLimitType == ENodeLimit::Limited", EditConditionHides))
	int32 ParentLimit;

	UPROPERTY(EditDefaultsOnly, Category = "NoiseGraphNode_Editor")
	ENodeLimit ChildrenLimitType;

	UPROPERTY(EditDefaultsOnly, Category = "NoiseGraphNode_Editor" ,meta = (ClampMin = "0",EditCondition = "ChildrenLimitType == ENodeLimit::Limited", EditConditionHides))
	int32 ChildrenLimit;
	
#endif

#if WITH_EDITOR
	virtual FLinearColor GetBackgroundColor() const;

	virtual FText GetNodeTitle() const;

	virtual void SetNodeTitle(const FText& NewTitle);

	virtual bool CanCreateConnection(UNoiseGraphNode* Other, FText& ErrorMessage);

	virtual bool CanCreateConnectionTo(UNoiseGraphNode* Other, int32 NumberOfChildrenNodes, FText& ErrorMessage);
	virtual bool CanCreateConnectionFrom(UNoiseGraphNode* Other, int32 NumberOfParentNodes, FText& ErrorMessage);
#endif
};
