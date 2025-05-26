#pragma once
#include "CoreMinimal.h"
#include "TeleporterComponent_Bool_EventDelegate.generated.h"

class UTeleporterSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTeleporterComponent_Bool_Event, UTeleporterSimulationComponent*, Component, bool, bState);

