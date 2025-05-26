#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AnimationContainerMapping.generated.h"

class UAnimationContainer;

USTRUCT(BlueprintType)
struct FAnimationContainerMapping {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag Tag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationContainer* AnimationContainer;
    
    LOC_API FAnimationContainerMapping();
};

