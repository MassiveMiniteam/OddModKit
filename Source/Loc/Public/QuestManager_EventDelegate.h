#pragma once
#include "CoreMinimal.h"
#include "QuestManager_EventDelegate.generated.h"

class UQuestManagerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FQuestManager_Event, UQuestManagerSimulationComponent*, QuestManagerSimulationComponent);

