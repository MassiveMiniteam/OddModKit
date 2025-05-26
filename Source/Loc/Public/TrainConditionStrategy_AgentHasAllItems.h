#pragma once
#include "CoreMinimal.h"
#include "TrainConditionStrategy.h"
#include "TrainConditionStrategy_AgentHasAllItems.generated.h"

UCLASS(Blueprintable)
class LOC_API UTrainConditionStrategy_AgentHasAllItems : public UTrainConditionStrategy {
    GENERATED_BODY()
public:
    UTrainConditionStrategy_AgentHasAllItems();

};

