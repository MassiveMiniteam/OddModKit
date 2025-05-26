#pragma once
#include "CoreMinimal.h"
#include "OnTweenUpdateEventDelegate.generated.h"

class UTweenBase;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTweenUpdateEvent, UTweenBase*, Tween, float, Progress);

