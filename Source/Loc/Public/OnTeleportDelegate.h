#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OnTeleportDelegate.generated.h"

class UUnitMovementSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnTeleport, UUnitMovementSimulationComponent*, FollowComponent, FIntVector, FromPosition, FIntVector, ToPosition);

