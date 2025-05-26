#pragma once
#include "CoreMinimal.h"
#include "BufferGateEventDelegate.generated.h"

class ULogicBufferGateSimulation;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBufferGateEvent, ULogicBufferGateSimulation*, Gate);

