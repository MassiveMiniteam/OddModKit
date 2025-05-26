#pragma once
#include "CoreMinimal.h"
#include "EMovementEndResult.h"
#include "OnMovementFinishedDelegate.generated.h"

class UUnitMovementSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMovementFinished, UUnitMovementSimulationComponent*, FollowComponent, EMovementEndResult, Result);

