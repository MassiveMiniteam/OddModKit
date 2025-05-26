#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "TagOnlyEventDelegate.generated.h"

class UStatsComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTagOnlyEvent, UStatsComponent*, StatsComponent, FGameplayTag, Tag);

