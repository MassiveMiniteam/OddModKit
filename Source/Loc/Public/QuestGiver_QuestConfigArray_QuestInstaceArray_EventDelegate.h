#pragma once
#include "CoreMinimal.h"
#include "QuestGiver_QuestConfigArray_QuestInstaceArray_EventDelegate.generated.h"

class AQuestInstance;
class UQuestConfig;
class UQuestGiverSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FQuestGiver_QuestConfigArray_QuestInstaceArray_Event, UQuestGiverSimulationComponent*, Component, TArray<UQuestConfig*>, Available, TArray<AQuestInstance*>, ActiveQuests);

