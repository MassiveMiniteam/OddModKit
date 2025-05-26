#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimMetaData.h"
#include "TurnAnimationMetaData.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LOC_API UTurnAnimationMetaData : public UAnimMetaData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultAnimationTurnSpeed;
    
    UTurnAnimationMetaData();

};

