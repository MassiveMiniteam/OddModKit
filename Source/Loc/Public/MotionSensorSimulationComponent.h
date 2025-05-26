#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Fixed.h"
#include "LogicSensorBaseSimulationComponent.h"
#include "MotionSensorEventDelegate.h"
#include "MotionSensorIntPointsEventDelegate.h"
#include "MotionSensorSimulationComponent.generated.h"

class ASimulationActor;
class USimulationTimerComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMotionSensorSimulationComponent : public ULogicSensorBaseSimulationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FMotionSensorIntPointsEvent OnMotionDetected;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FMotionSensorEvent OnMotionDetectionCooldownPhaseOver;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference ResetMotionSensorTimerReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed MotionSensorResetTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRecognizeChangeOnRemoval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USimulationTimerComponent* MotionSensorResetTimer;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<ASimulationActor>, FIntVector> ObservedActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bSignal;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsInCooldownPhase;
    
public:
    UMotionSensorSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnMotionSensorResetTimerFired(USimulationTimerComponent* SimulationTimerComponent);
    
};

