#pragma once
#include "CoreMinimal.h"
#include "SerializedSimulationObject.h"
#include "BossSubPhase.h"
#include "EBossResetReason.h"
#include "BossPhase.generated.h"

class AQuestInstance;
class ASimulationPlayer;
class UBossPhasesSimulationComponent;
class UQuestManagerSimulationComponent;
class URecipeConfig;

UCLASS(Blueprintable)
class LOC_API UBossPhase : public USerializedSimulationObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UBossPhasesSimulationComponent> BossPhaseComponent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBossSubPhase> SubPhases;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ActiveSubPhaseIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URecipeConfig* ActiveRecipe;
    
public:
    UBossPhase();

    UFUNCTION(BlueprintCallable)
    void UpdateHostilityLevelForCurrentSubphase();
    
    UFUNCTION(BlueprintCallable)
    void StartPhase();
    
    UFUNCTION(BlueprintCallable)
    void ResetPhase(EBossResetReason Reason);
    
    UFUNCTION(BlueprintCallable)
    void PhaseProgressChanged(int32 LastProgress, int32 CurrentProgress);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnStopSubPhase(const FBossSubPhase& Subphase);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnStartSubPhase(const FBossSubPhase& Subphase);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartPhase();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnResetPhase(EBossResetReason Reason);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnQuestCompleted(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* QuestInstance, ASimulationPlayer* SimulationPlayer);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPhaseProgressChanged(int32 LastProgress, int32 CurrentProgress);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInit();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEndPhase();
    
    UFUNCTION(BlueprintCallable)
    void Init();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetActiveSubPhaseIndex() const;
    
    UFUNCTION(BlueprintCallable)
    void EndPhase();
    
};

