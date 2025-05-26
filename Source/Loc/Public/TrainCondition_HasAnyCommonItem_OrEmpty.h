#pragma once
#include "CoreMinimal.h"
#include "TrainConditionStrategy.h"
#include "TrainCondition_HasAnyCommonItem_OrEmpty.generated.h"

UCLASS(Blueprintable)
class LOC_API UTrainCondition_HasAnyCommonItem_OrEmpty : public UTrainConditionStrategy {
    GENERATED_BODY()
public:
    UTrainCondition_HasAnyCommonItem_OrEmpty();

};

