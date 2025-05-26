#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "LogicSensorBaseSimulationComponent.h"
#include "LogicTrainSensorEventDelegate.h"
#include "LogicTrainSensor.generated.h"

class UInventoryComponent;
class UTrainTracksAgentSimulationComponent;
class UTrainTracksPoleBaseSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULogicTrainSensor : public ULogicSensorBaseSimulationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLogicTrainSensorEvent OnTrainDetected;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLogicTrainSensorEvent OnTargetPoleChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bCurrentState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference FilterInventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* FilterInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTrainTracksPoleBaseSimulationComponent> TrainPole;
    
public:
    ULogicTrainSensor(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnTrainReachedPole(const UTrainTracksPoleBaseSimulationComponent* Pole, const UTrainTracksAgentSimulationComponent* Agent);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTrainTracksPoleBaseSimulationComponent* GetTrainPole() const;
    
private:
    UFUNCTION(BlueprintCallable)
    void FindTarget();
    
};

