#pragma once
#include "CoreMinimal.h"
#include "SimulationActor.h"
#include "QuestInstance_QuestStep_Bool_EventDelegate.h"
#include "QuestInstance.generated.h"

class ASimulationPlayer;
class UQuestConfig;
class UQuestGiverSimulationComponent;
class UQuestManagerSimulationComponent;
class UQuestStepBehaviour;
class USimulationTimerComponent;
class UStatsComponent;

UCLASS(Blueprintable)
class LOC_API AQuestInstance : public ASimulationActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestInstance_QuestStep_Bool_Event OnAnyQuestStepUpdated;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatsComponent* StatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USimulationTimerComponent* AutoCompleteTimerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UQuestConfig* QuestData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UQuestStepBehaviour*> QuestStepBehaviours;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UQuestGiverSimulationComponent* QuestGiverComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQuestManagerSimulationComponent* QuestManager;
    
public:
    AQuestInstance(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetQuestGiverComponent(UQuestGiverSimulationComponent* InQuestGiverComponent);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnCompleteQuestTimerFired(USimulationTimerComponent* SimulationTimerComponent);
    
    UFUNCTION(BlueprintCallable)
    void OnAnyQuestStepStateChanged(UQuestStepBehaviour* QuestStepBehaviour, bool bState);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UQuestGiverSimulationComponent* GetQuestGiverComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UQuestConfig* GetQuestData() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASimulationPlayer*> GetPlayers();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanComplete(ASimulationPlayer* SimulationPlayer);
    
    UFUNCTION(BlueprintCallable)
    void AutoComplete();
    
};

