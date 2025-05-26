#pragma once
#include "CoreMinimal.h"
#include "EBossResetReason.h"
#include "BossPhaseResetEventDelegate.generated.h"

class UBossPhasesSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBossPhaseResetEvent, UBossPhasesSimulationComponent*, BossPhasesSimulationComponent, EBossResetReason, Reason);

