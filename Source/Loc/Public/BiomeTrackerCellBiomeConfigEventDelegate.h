#pragma once
#include "CoreMinimal.h"
#include "BiomeTrackerCellBiomeConfigEventDelegate.generated.h"

class UBiomeConfig;
class UBiomeTrackerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBiomeTrackerCellBiomeConfigEvent, UBiomeTrackerSimulationComponent*, Component, UBiomeConfig*, BiomeConfig);

