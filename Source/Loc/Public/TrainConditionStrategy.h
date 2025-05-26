#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TrainConditionStrategy.generated.h"

class ASimulationActor;
class UTrainTracksAgentSimulationComponent;

UCLASS(Abstract, Blueprintable)
class LOC_API UTrainConditionStrategy : public UObject {
    GENERATED_BODY()
public:
    UTrainConditionStrategy();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsConditionSatisfied(const UTrainTracksAgentSimulationComponent* Agent, const ASimulationActor* OtherActor) const;
    
};

