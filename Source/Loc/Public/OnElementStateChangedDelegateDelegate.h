#pragma once
#include "CoreMinimal.h"
#include "ElementState.h"
#include "OnElementStateChangedDelegateDelegate.generated.h"

class UElementStateSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnElementStateChangedDelegate, UElementStateSimulationComponent*, Component, FElementState, OldElementalState);

