#pragma once
#include "CoreMinimal.h"
#include "OnEventTriggeredDynamicMulticastDelegate.generated.h"

class UEventDataAsset;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEventTriggeredDynamicMulticast, UEventDataAsset*, EventDataAsset);

