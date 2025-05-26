#pragma once
#include "CoreMinimal.h"
#include "EventDataAssetStateChangeDelegate.generated.h"

class UEventDataAssetWithState;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEventDataAssetStateChange, UEventDataAssetWithState*, EventDatAsset, bool, bState);

