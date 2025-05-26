#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "BossPhaseEventDelegate.h"
#include "BossPhaseResetEventDelegate.h"
#include "BossSubPhaseEventDelegate.h"
#include "EBossResetReason.h"
#include "Templates/SubclassOf.h"
#include "BossPhasesSimulationComponent.generated.h"

class AQuestInstance;
class UBossPhase;
class UElementStateSimulationComponent;
class UIncubatorSimulationComponent;
class UQuestManagerSimulationComponent;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UBossPhasesSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UBossPhase* ActiveBossPhase;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBossSubPhaseEvent OnSubphaseStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBossSubPhaseEvent OnSubphaseStopped;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBossPhaseResetEvent OnBossPhaseReset;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBossPhaseEvent OnBossPhaseStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBossPhaseEvent OnBossPhaseEnd;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UQuestManagerSimulationComponent> QuestManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UIncubatorSimulationComponent> IncubatorSimulationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UElementStateSimulationComponent> ElementState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 LastProgress;
    
public:
    UBossPhasesSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StartBossPhase(TSubclassOf<UBossPhase> BossPhaseClass);
    
    UFUNCTION(BlueprintCallable)
    void ResetGridPosition(FIntPoint& Pos);
    
    UFUNCTION(BlueprintCallable)
    void ResetActiveBossPhaseIgnoreIncubatorProgress(EBossResetReason Reason);
    
    UFUNCTION(BlueprintCallable)
    void ResetActiveBossPhase(EBossResetReason Reason);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnStatChanged(UStatsComponent* StatsComponentIn, FGameplayTag Tag, FFixed OldValue, FFixed NewValue);
    
    UFUNCTION(BlueprintCallable)
    void OnQuestAccepted(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* QuestInstance);
    
    UFUNCTION(BlueprintCallable)
    void OnIncubatorProgressionChanged(UIncubatorSimulationComponent* Incubator, FFixed Progress);
    
    UFUNCTION(BlueprintCallable)
    void OnIncubatorCompleted(UIncubatorSimulationComponent* Incubator, FFixed Progress);
    
    UFUNCTION(BlueprintCallable)
    void InitReferences();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UBossPhase* GetActiveBossPhase() const;
    
    UFUNCTION(BlueprintCallable)
    void EndActiveBossPhase();
    
};

