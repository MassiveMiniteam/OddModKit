#pragma once
#include "CoreMinimal.h"
#include "TimedGameplayStatCurceChanged_EventDelegate.generated.h"

class UCraftedRecipesCounterSimulationComponent;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTimedGameplayStatCurceChanged_Event, UCraftedRecipesCounterSimulationComponent*, Component, int64, Value);

