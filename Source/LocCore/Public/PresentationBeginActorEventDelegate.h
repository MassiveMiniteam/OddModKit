#pragma once
#include "CoreMinimal.h"
#include "PresentationBeginActorEventDelegate.generated.h"

class APresentationActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPresentationBeginActorEvent, APresentationActor*, Actor);

