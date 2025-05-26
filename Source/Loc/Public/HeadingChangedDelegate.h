#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HeadingChangedDelegate.generated.h"

class UPositionHeadingSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FHeadingChanged, UPositionHeadingSimulationComponent*, PositionHeading, FIntPoint, LastHeading, FIntPoint, NewHeading);

