#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimMetaData.h"
#include "GameplayTagContainer.h"
#include "TaggedAnimationData.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LOC_API UTaggedAnimationData : public UAnimMetaData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    UTaggedAnimationData();

};

