#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Fixed.h"
#include "PaintReceiverEventDelegate.generated.h"

class UColorItemConfig;
class UPaintReceiverSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FPaintReceiverEvent, UPaintReceiverSimulationComponent*, PaintReceiverSimulationComponent, UColorItemConfig*, ColorItem, FIntVector, ImpactLocation, FFixed, Delay);

