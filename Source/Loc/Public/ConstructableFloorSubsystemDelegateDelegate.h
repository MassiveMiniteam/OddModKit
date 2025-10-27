#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ConstructableFloorSubsystemDelegateDelegate.generated.h"

class ASimulationPlayer;
class UConstructableFloorTilesSubsystem;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FConstructableFloorSubsystemDelegate, UConstructableFloorTilesSubsystem*, Subsystem, FIntPoint, GridIndex, bool, bFloorTileWasPlaced, ASimulationPlayer*, ExecutingPlayer);

