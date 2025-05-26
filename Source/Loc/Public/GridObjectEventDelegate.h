#pragma once
#include "CoreMinimal.h"
#include "GridObjectEventDelegate.generated.h"

class AGridObject;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGridObjectEvent, AGridObject*, GridObject);

