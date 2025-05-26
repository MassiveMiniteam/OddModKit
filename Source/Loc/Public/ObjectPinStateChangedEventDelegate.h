#pragma once
#include "CoreMinimal.h"
#include "ObjectPinStateChangedEventDelegate.generated.h"

class ASimulationPlayer;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FObjectPinStateChangedEvent, bool, bObjectIsPinned, ASimulationPlayer*, Player);

