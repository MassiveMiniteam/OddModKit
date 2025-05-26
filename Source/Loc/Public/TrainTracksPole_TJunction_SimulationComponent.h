#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TrainTracksPoleBaseSimulationComponent.h"
#include "TrainTracksPole_TJunction_SimulationComponent.generated.h"

class ULogicInputSimulationComponent;
class ULogicOutputSimulationComponent;
class USimulationTimerComponent;
class UTrainConditionStrategy;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UTrainTracksPole_TJunction_SimulationComponent : public UTrainTracksPoleBaseSimulationComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTrainConditionStrategy> JunctionCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTrainConditionStrategy> SensorCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULogicInputSimulationComponent* LogicInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULogicOutputSimulationComponent* LogicOutput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USimulationTimerComponent* SensorSignalSendDelayTimer;
    
public:
    UTrainTracksPole_TJunction_SimulationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnSensorDelayTimerFired(USimulationTimerComponent* SimulationTimerComponent);
    
};

