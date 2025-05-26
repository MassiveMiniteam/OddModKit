#pragma once
#include "CoreMinimal.h"
#include "BossSubPhase.h"
#include "BossSubPhaseEventDelegate.generated.h"

class UBossPhase;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBossSubPhaseEvent, UBossPhase*, BossPhase, FBossSubPhase, Subphase);

