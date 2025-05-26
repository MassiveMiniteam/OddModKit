#pragma once
#include "CoreMinimal.h"
#include "VillageSubsystem_EventDelegate.generated.h"

class UVillageLoadSimulationSubsystem;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVillageSubsystem_Event, UVillageLoadSimulationSubsystem*, VillageSubsystem);

