#pragma once
#include "CoreMinimal.h"
#include "OnBlackboardKeyChangedEventDelegate.generated.h"

class USimulationBlackboardComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBlackboardKeyChangedEvent, const USimulationBlackboardComponent*, BlackboardComponent, FName, Key);

