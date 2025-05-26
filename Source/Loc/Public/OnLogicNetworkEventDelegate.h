#pragma once
#include "CoreMinimal.h"
#include "OnLogicNetworkEventDelegate.generated.h"

class ALogicNetwork;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLogicNetworkEvent, ALogicNetwork*, Network);

