#pragma once
#include "CoreMinimal.h"
#include "SimpleStatsCompEventDelegate.generated.h"

class UStatsComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSimpleStatsCompEvent, UStatsComponent*, StatsComponent);

