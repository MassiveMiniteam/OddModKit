#pragma once
#include "CoreMinimal.h"
#include "GridObjectConditionEventDelegate.generated.h"

class AGridObject;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_RetVal_OneParam(bool, FGridObjectConditionEvent, AGridObject*, GridObject);

