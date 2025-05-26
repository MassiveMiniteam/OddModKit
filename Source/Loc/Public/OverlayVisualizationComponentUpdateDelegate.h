#pragma once
#include "CoreMinimal.h"
#include "OverlayVisualizationComponentUpdateDelegate.generated.h"

class UOverlayVisualizationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOverlayVisualizationComponentUpdate, UOverlayVisualizationComponent*, Component, bool, bIsVisulizationActive);

