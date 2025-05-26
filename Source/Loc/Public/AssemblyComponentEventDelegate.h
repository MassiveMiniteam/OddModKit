#pragma once
#include "CoreMinimal.h"
#include "AssemblyComponentEventDelegate.generated.h"

class UConstructionAssemblySimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAssemblyComponentEvent, UConstructionAssemblySimulationComponent*, Component);

