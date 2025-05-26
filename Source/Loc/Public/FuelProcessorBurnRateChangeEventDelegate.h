#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "FuelProcessorBurnRateChangeEventDelegate.generated.h"

class UFuelProcessorSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFuelProcessorBurnRateChangeEvent, UFuelProcessorSimulationComponent*, Component, FFixed, OldBurnRate);

