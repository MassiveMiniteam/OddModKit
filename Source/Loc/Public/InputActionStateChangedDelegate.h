#pragma once
#include "CoreMinimal.h"
#include "InputActionStateChangedDelegate.generated.h"

class ALocPlayerController;
class UInputActionData;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInputActionStateChanged, UInputActionData*, InputAction, ALocPlayerController*, Player);

