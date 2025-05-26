#pragma once
#include "CoreMinimal.h"
#include "ChildPresentationActor.h"
#include "TrainAgentGridPositionIndicator.generated.h"

class UPositionSimulationComponent;

UCLASS(Blueprintable)
class LOC_API ATrainAgentGridPositionIndicator : public AChildPresentationActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPositionSimulationComponent* PositionSimulationComponent;
    
public:
    ATrainAgentGridPositionIndicator(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnContextUpdated();
    
};

