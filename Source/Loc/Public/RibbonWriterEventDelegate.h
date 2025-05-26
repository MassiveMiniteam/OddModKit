#pragma once
#include "CoreMinimal.h"
#include "RibbonWriterEventDelegate.generated.h"

class ULogicRibbonWriterSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRibbonWriterEvent, ULogicRibbonWriterSimulationComponent*, RibbonWriter);

