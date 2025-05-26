#pragma once
#include "CoreMinimal.h"
#include "InventoryMetaEventDelegate.generated.h"

class UInventoryMetaSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryMetaEvent, UInventoryMetaSimulationComponent*, MetaComponent);

