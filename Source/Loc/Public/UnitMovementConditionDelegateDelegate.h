#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UnitMovementConditionDelegateDelegate.generated.h"

class UUnitMovementSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_RetVal_ThreeParams(bool, FUnitMovementConditionDelegate, UUnitMovementSimulationComponent*, FollowComponent, FIntVector, FromPosition, FIntVector, ToPosition);

