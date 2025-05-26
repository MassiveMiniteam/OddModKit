#pragma once
#include "CoreMinimal.h"
#include "OnGateStateChangedDelegate.generated.h"

class UPathAddOn_CompleteBlockToggle_SimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGateStateChanged, UPathAddOn_CompleteBlockToggle_SimulationComponent*, Component, bool, bGateIsCurrentlyClosed);

