#pragma once
#include "CoreMinimal.h"
#include "OnAssignedMinionChangedDelegate.generated.h"

class UItemMinionConfig;
class UMinionAssignSlotWidget;
class UMinionControllerSimulationBaseComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnAssignedMinionChanged, UMinionAssignSlotWidget*, MinionAssignSlot, UMinionControllerSimulationBaseComponent*, MinionController, int32, SelectedIndex, UItemMinionConfig*, SelectedMinionConfig);

