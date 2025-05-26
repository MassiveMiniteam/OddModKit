#pragma once
#include "CoreMinimal.h"
#include "OnGridNetworkSimulationComponentUpdatedDelegate.generated.h"

class UGridNetworkSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGridNetworkSimulationComponentUpdated, UGridNetworkSimulationComponent*, Component);

