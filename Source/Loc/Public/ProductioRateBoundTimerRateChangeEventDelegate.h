#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "ProductioRateBoundTimerRateChangeEventDelegate.generated.h"

class UProductionRateBoundTimerComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FProductioRateBoundTimerRateChangeEvent, UProductionRateBoundTimerComponent*, Component, FFixed, NewRate);

