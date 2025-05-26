#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "OnCarouselChangedValueDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCarouselChangedValue, int32, Index, FGameplayTag, Tag, FText, Text);

