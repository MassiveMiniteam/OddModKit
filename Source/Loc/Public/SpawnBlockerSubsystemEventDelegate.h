#pragma once
#include "CoreMinimal.h"
#include "SpawnBlockerSubsystemEventDelegate.generated.h"

class USpawnBlockerComponent;
class USpawnBlockerSimulationSubsystem;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSpawnBlockerSubsystemEvent, USpawnBlockerSimulationSubsystem*, Subsystem, USpawnBlockerComponent*, SpawnBlocker);

