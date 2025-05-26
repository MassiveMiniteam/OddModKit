#pragma once
#include "CoreMinimal.h"
#include "SlotChangedEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSlotChangedEvent, int32, SlotIndex);

