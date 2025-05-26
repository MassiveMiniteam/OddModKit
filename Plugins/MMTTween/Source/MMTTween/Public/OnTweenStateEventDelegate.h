#pragma once
#include "CoreMinimal.h"
#include "OnTweenStateEventDelegate.generated.h"

class UTweenBase;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTweenStateEvent, UTweenBase*, Tween);

