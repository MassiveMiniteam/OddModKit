#pragma once
#include "CoreMinimal.h"
#include "RibbonReaderEventDelegate.generated.h"

class ULogicRibbonReaderSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRibbonReaderEvent, ULogicRibbonReaderSimulationComponent*, RibbonReader);

