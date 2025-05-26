#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "OnGameplayStatIncreasedDelegate.generated.h"

class UStatsComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnGameplayStatIncreased, UStatsComponent*, StatsComponent, FGameplayTag, Tag, FFixed, NewValue);

