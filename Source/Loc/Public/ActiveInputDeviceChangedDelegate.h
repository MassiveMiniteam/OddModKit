#pragma once
#include "CoreMinimal.h"
#include "ActiveInputDeviceChangedDelegate.generated.h"

class UInputDeviceMapping;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActiveInputDeviceChanged, UInputDeviceMapping*, InputDevice);

