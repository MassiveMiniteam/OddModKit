#pragma once
#include "CoreMinimal.h"
#include "EMapIconInteractionType.h"
#include "MapIconPlayerInteraction_EventDelegate.generated.h"

class ASimulationPlayer;
class UMapIconSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FMapIconPlayerInteraction_Event, UMapIconSimulationComponent*, MapIcon, ASimulationPlayer*, Player, EMapIconInteractionType, InteractionType);

