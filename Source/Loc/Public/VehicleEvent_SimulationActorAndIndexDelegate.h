#pragma once
#include "CoreMinimal.h"
#include "VehicleEvent_SimulationActorAndIndexDelegate.generated.h"

class ASimulationActor;
class UVehicleSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FVehicleEvent_SimulationActorAndIndex, UVehicleSimulationComponent*, Component, ASimulationActor*, SimulationActor, int32, Index);

