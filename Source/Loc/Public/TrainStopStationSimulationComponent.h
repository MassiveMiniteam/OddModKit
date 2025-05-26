#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "InteractionInterface.h"
#include "ETrainStopStationMode.h"
#include "SimulationTimerComponent.h"
#include "Templates/SubclassOf.h"
#include "TrainStopComponent_DelegateDelegate.h"
#include "TrainStopStationSimulationComponent.generated.h"

class UGameplayEffect;
class ULogicConnectionSimulationComponent;
class ULogicInputSimulationComponent;
class UTrainTracksAgentSimulationComponent;
class UTrainTracksPoleBaseSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UTrainStopStationSimulationComponent : public USimulationTimerComponent, public IInteractionInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrainStopComponent_Delegate OnPlayerManualStopTriggered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrainStopComponent_Delegate OnStationModeChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ETrainStopStationMode Mode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed TimerDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed InventoryCheckInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bPlayerManualStopTriggered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTrainTracksPoleBaseSimulationComponent* PoleComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULogicInputSimulationComponent*> LogicInputs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayEffect> StopLocomotiveGameplayEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UGameplayEffect> GameplayEffectReference;
    
public:
    UTrainStopStationSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetTimerDuration(FFixed NewTimerDuration);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnLogicSignalChanged(ULogicConnectionSimulationComponent* Input);
    
    UFUNCTION(BlueprintCallable)
    void OnGameplayEffectRemoved();
    
    UFUNCTION(BlueprintCallable)
    void OnAgentStartsMoving(const UTrainTracksPoleBaseSimulationComponent* Pole, const UTrainTracksAgentSimulationComponent* Agent);
    
    UFUNCTION(BlueprintCallable)
    void OnAgentArrives(const UTrainTracksPoleBaseSimulationComponent* Pole, const UTrainTracksAgentSimulationComponent* Agent);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerCustomBlockActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocomotiveHereWaiting() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCurrentlyStoppingIncomingLocomotives() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsConnectedToAnyLogicInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBlockedByLogic() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetTimerDuration() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetRelativeCargoAmountOfCompleteTrain() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ETrainStopStationMode GetMode() const;
    
    UFUNCTION(BlueprintCallable)
    void ChangeMode(ETrainStopStationMode NewMode);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AnyLogicInputBlocks() const;
    

    // Fix for true pure virtual functions not being implemented
};

