#pragma once
#include "CoreMinimal.h"
#include "OnCraftingPlayerEventDelegate.generated.h"

class ASimulationPlayer;
class UManpowerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCraftingPlayerEvent, UManpowerSimulationComponent*, Component, ASimulationPlayer*, Player);

