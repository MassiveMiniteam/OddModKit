#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RandomRadialSpawnerEventDelegate.generated.h"

class URandomRadialSpawnerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRandomRadialSpawnerEvent, URandomRadialSpawnerSimulationComponent*, Component, const TArray<FIntVector>&, SpawnPositions);

