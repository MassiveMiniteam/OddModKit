#pragma once
#include "CoreMinimal.h"
#include "AssemblyEventDelegate.generated.h"

class ASimulationPlayer;
class UConstructionAssemblySimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAssemblyEvent, UConstructionAssemblySimulationComponent*, Component, ASimulationPlayer*, ExecutingSimulationPlayer);

