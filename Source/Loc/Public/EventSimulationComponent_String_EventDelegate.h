#pragma once
#include "CoreMinimal.h"
#include "EventSimulationComponent_String_EventDelegate.generated.h"

class UEventSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEventSimulationComponent_String_Event, UEventSimulationComponent*, Component, const FString&, EventId);

