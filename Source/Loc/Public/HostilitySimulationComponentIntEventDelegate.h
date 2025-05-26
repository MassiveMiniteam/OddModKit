#pragma once
#include "CoreMinimal.h"
#include "HostilitySimulationComponentIntEventDelegate.generated.h"

class UCachedAvailableBudgetSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHostilitySimulationComponentIntEvent, UCachedAvailableBudgetSimulationComponent*, Component, int32, CachedBudget);

