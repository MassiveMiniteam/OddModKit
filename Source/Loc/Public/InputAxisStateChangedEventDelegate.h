#pragma once
#include "CoreMinimal.h"
#include "InputAxisStateChangedEventDelegate.generated.h"

class ALocPlayerController;
class UInputActionData;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_TwoParams(FInputAxisStateChangedEvent, UInputActionData*, InputAction, ALocPlayerController*, Player);

