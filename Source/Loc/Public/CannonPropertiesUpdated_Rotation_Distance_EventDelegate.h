#pragma once
#include "CoreMinimal.h"
#include "CannonPropertiesUpdated_Rotation_Distance_EventDelegate.generated.h"

class UCannonSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FCannonPropertiesUpdated_Rotation_Distance_Event, UCannonSimulationComponent*, CannonComponent, int32, Rotation, int32, Distance);

