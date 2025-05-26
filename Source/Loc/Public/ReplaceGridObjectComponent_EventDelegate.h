#pragma once
#include "CoreMinimal.h"
#include "ReplaceGridObjectComponent_EventDelegate.generated.h"

class ASimulationPlayer;
class UReplaceGridObjectOnConditionComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FReplaceGridObjectComponent_Event, UReplaceGridObjectOnConditionComponent*, Component, ASimulationPlayer*, Player);

