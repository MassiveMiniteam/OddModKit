#pragma once
#include "CoreMinimal.h"
#include "ConstructableFloorSubsystemDelegate_OnlyPlayerDelegate.generated.h"

class ASimulationPlayer;
class UConstructableFloorTilesSubsystem;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FConstructableFloorSubsystemDelegate_OnlyPlayer, UConstructableFloorTilesSubsystem*, Subsystem, ASimulationPlayer*, ExecutingPlayer);

