#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimMetaData.h"
#include "MovementAnimationMetaData.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LOC_API UMovementAnimationMetaData : public UAnimMetaData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultAnimationMovementSpeed;
    
    UMovementAnimationMetaData();

};

