#pragma once
#include "CoreMinimal.h"
#include "OnSliderAcceptedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSliderAccepted, float, Value);

