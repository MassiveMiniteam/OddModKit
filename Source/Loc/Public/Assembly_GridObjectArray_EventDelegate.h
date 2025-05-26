#pragma once
#include "CoreMinimal.h"
#include "Assembly_GridObjectArray_EventDelegate.generated.h"

class AGridObject;
class ASimulationPlayer;
class UConstructionAssemblySimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAssembly_GridObjectArray_Event, UConstructionAssemblySimulationComponent*, Component, ASimulationPlayer*, ExecutingSimulationPlayer, TArray<AGridObject*>, GridObjects);

