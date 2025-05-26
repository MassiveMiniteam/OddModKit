#pragma once
#include "CoreMinimal.h"
#include "OnGridNetworkEventDelegate.generated.h"

class AGridNetwork;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGridNetworkEvent, AGridNetwork*, Instance);

