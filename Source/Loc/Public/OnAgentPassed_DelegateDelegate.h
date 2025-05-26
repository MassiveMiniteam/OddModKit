#pragma once
#include "CoreMinimal.h"
#include "ItemStack.h"
#include "OnAgentPassed_DelegateDelegate.generated.h"

class UGridNetworkAgentSimulationComponent;
class UPathAddOn_ItemThroughputMeter_SimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAgentPassed_Delegate, UPathAddOn_ItemThroughputMeter_SimulationComponent*, ItemThroughputMeter, UGridNetworkAgentSimulationComponent*, Agent, const TArray<FItemStack>&, CarriedItems);

