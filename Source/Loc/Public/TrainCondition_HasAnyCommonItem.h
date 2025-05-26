#pragma once
#include "CoreMinimal.h"
#include "TrainConditionStrategy.h"
#include "TrainCondition_HasAnyCommonItem.generated.h"

UCLASS(Blueprintable)
class LOC_API UTrainCondition_HasAnyCommonItem : public UTrainConditionStrategy {
    GENERATED_BODY()
public:
    UTrainCondition_HasAnyCommonItem();

};

