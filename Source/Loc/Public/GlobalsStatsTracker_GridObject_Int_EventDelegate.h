#pragma once
#include "CoreMinimal.h"
#include "GlobalsStatsTracker_GridObject_Int_EventDelegate.generated.h"

class AGridObject;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGlobalsStatsTracker_GridObject_Int_Event, AGridObject*, GridObject, int32, Value);

