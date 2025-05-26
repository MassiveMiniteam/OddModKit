#pragma once
#include "CoreMinimal.h"
#include "EDestructionReason.h"
#include "PresentationActorEventDelegate.generated.h"

class APresentationActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPresentationActorEvent, APresentationActor*, Actor, EDestructionReason, Reason);

