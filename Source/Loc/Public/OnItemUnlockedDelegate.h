#pragma once
#include "CoreMinimal.h"
#include "OnItemUnlockedDelegate.generated.h"

class UUnlockableDataAsset;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemUnlocked, UUnlockableDataAsset*, UnlockableDataAsset);

