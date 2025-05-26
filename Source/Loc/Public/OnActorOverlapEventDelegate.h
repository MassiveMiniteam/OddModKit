#pragma once
#include "CoreMinimal.h"
#include "OnActorOverlapEventDelegate.generated.h"

class ASimulationActor;
class UActorOverlapSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActorOverlapEvent, UActorOverlapSimulationComponent*, Component, ASimulationActor*, OtherActor);

