#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "GameplayStatChangedEventDelegate.generated.h"

class UStatsComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FGameplayStatChangedEvent, UStatsComponent*, StatsComponent, FGameplayTag, Tag, FFixed, OldValue, FFixed, NewValue);

