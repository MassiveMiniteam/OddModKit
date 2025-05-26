#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OnPathToTargetUpdatedDelegate.generated.h"

class UUnitMovementSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPathToTargetUpdated, UUnitMovementSimulationComponent*, FollowComponent, FIntVector, CurrentPosition);

