#pragma once
#include "CoreMinimal.h"
#include "EVisibilityState.h"
#include "OnPresentationStateChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPresentationStateChanged, TEnumAsByte<EVisibilityState>, NewState);

