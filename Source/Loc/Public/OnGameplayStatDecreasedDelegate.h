#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "OnGameplayStatDecreasedDelegate.generated.h"

class UStatsComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnGameplayStatDecreased, UStatsComponent*, StatsComponent, FGameplayTag, Tag, FFixed, NewValue);

