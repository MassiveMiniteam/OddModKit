#pragma once
#include "CoreMinimal.h"
#include "IdleAnimationComponent_EventDelegate.generated.h"

class UIdleAnimationPresentationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIdleAnimationComponent_Event, UIdleAnimationPresentationComponent*, Component);

