#pragma once
#include "CoreMinimal.h"
#include "GasBlocker_Bool_EventDelegate.generated.h"

class UGasBlockerComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGasBlocker_Bool_Event, UGasBlockerComponent*, GasBlocker, bool, bState);

