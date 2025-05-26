#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SimulationActorComponent.h"
#include "TutorialManagerSimulationComponent.generated.h"

class AQuestInstance;
class ASimulationPlayer;
class UObject;
class UQuestConfig;
class UQuestManagerSimulationComponent;
class USimulationTimerComponent;
class UTutorialManagerSimulationComponent;
class UUnlockableDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UTutorialManagerSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQuestManagerSimulationComponent* QuestManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUnlockableDataAsset* TutorialUnlockable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UQuestConfig* FirstQuestAfterTutorial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UQuestConfig*> TutorialQuests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UUnlockableDataAsset*> PostTutorialUnlockables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UQuestConfig* ActiveQuestConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 TutorialStepIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WaitIntervalBetweenTutorialSteps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference TutorialStepsDelayTimerRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USimulationTimerComponent* TutorialStepsTimer;
    
public:
    UTutorialManagerSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StartTutorialFromBeginning();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnUnlock(UUnlockableDataAsset* UnlockableDataAsset);
    
    UFUNCTION(BlueprintCallable)
    void OnTutorialStepsDelayTimerFired(USimulationTimerComponent* SimulationTimerComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTutorialStart();
    
    UFUNCTION(BlueprintCallable)
    void OnQuestCompleted(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* QuestInstance, ASimulationPlayer* SimulationPlayer);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTutorialFinished();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTutorialEnabled();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static UTutorialManagerSimulationComponent* Get(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable)
    void ContinueOrStartTutorial();
    
};

