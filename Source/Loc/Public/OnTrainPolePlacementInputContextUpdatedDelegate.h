#pragma once
#include "CoreMinimal.h"
#include "OnTrainPolePlacementInputContextUpdatedDelegate.generated.h"

class UInputContextTrainPolePlacement;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTrainPolePlacementInputContextUpdated, UInputContextTrainPolePlacement*, InputContext);

