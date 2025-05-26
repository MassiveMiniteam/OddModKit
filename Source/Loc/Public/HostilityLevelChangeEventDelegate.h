#pragma once
#include "CoreMinimal.h"
#include "EvolutionBudget.h"
#include "HostilityLevelChangeEventDelegate.generated.h"

class UHostilityLevelSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHostilityLevelChangeEvent, UHostilityLevelSimulationComponent*, HostiltyLevelComponent, FEvolutionBudget, EvolutionBudget);

