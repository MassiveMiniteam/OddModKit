#pragma once
#include "CoreMinimal.h"
#include "InputAxisStateChangedDelegate.generated.h"

class ALocPlayerController;
class UInputActionData;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInputAxisStateChanged, UInputActionData*, InputAction, ALocPlayerController*, Player);

