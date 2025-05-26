#pragma once
#include "CoreMinimal.h"
#include "InputActionStateChangedEventDelegate.generated.h"

class ALocPlayerController;
class UInputActionData;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_TwoParams(FInputActionStateChangedEvent, UInputActionData*, InputAction, ALocPlayerController*, Player);

