#pragma once
#include "CoreMinimal.h"
#include "RegistrationSubsystemEventDelegate.generated.h"

class UComponentRegistrationSubsystem;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRegistrationSubsystemEvent, UComponentRegistrationSubsystem*, Subsystem);

