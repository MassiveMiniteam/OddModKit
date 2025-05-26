#pragma once
#include "CoreMinimal.h"
#include "RegistrationSubsystem_WithComponent_EventDelegate.generated.h"

class UComponentRegistrationSubsystem;
class URegisteredSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRegistrationSubsystem_WithComponent_Event, UComponentRegistrationSubsystem*, Subsystem, URegisteredSimulationComponent*, Component);

