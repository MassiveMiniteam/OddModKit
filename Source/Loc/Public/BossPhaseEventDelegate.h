#pragma once
#include "CoreMinimal.h"
#include "BossPhaseEventDelegate.generated.h"

class UBossPhasesSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBossPhaseEvent, UBossPhasesSimulationComponent*, BossPhasesSimulationComponent);

