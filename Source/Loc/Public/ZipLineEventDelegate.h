#pragma once
#include "CoreMinimal.h"
#include "ZipLineEventDelegate.generated.h"

class UItemTransferActorPairSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FZipLineEvent, UItemTransferActorPairSimulationComponent*, Component);

