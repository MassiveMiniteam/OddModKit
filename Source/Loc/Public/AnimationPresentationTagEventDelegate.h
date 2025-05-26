#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AnimationPresentationTagEventDelegate.generated.h"

class UAnimationPresentationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAnimationPresentationTagEvent, UAnimationPresentationComponent*, AnimationPresentationComponent, FGameplayTag, Tag);

