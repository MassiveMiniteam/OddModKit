#pragma once
#include "CoreMinimal.h"
#include "InputPressedDurationChangedEventDelegate.generated.h"

class UInputActionData;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInputPressedDurationChangedEvent, UInputActionData*, InputAction);

