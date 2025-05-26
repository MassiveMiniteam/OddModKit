#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "EQuestState.h"
#include "QuestManager_EventDelegate.h"
#include "QuestManager_QuestInstance_EventDelegate.h"
#include "QuestManager_QuestInstance_Player_EventDelegate.h"
#include "QuestManager_QuestStep_EventDelegate.h"
#include "QuestManagerSimulationComponent.generated.h"

class AQuestInstance;
class ASimulationManager;
class ASimulationPlayer;
class UObject;
class UQuestConfig;
class UQuestGiverSimulationComponent;
class UQuestStepBehaviour;
class UUnlockHandlingSimulationComponent;
class UUnlockableDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UQuestManagerSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestManager_QuestInstance_Event OnQuestPinned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestManager_QuestInstance_Event OnQuestUnpinned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestManager_QuestInstance_Player_Event OnQuestCompleted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestManager_QuestInstance_Player_Event OnQuestAborted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestManager_QuestInstance_Event OnNewQuestAccepted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestManager_Event OnUpdateAvailableQuests;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestManager_QuestStep_Event OnAnyQuestStepUpdated;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<AQuestInstance*> PinnedQuests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UQuestConfig* FirstQuest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UQuestConfig*> QuestPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UQuestConfig*> FailedQuests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UQuestConfig*> CompletedQuests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<AQuestInstance*> ActiveQuests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASimulationManager* SimulationManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUnlockHandlingSimulationComponent* UnlockHandlingSimulationComponent;
    
public:
    UQuestManagerSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void RemovePinnedQuest(AQuestInstance* QuestInstance);
    
    UFUNCTION(BlueprintCallable)
    void PinQuest(AQuestInstance* QuestInstance);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnItemUnlocked(UUnlockableDataAsset* UnlockableDataAsset);
    
    UFUNCTION(BlueprintCallable)
    void OnAnyQuestStepBehaviourUpdated(UQuestStepBehaviour* QuestStep);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsQuestDisqualified(UObject* WorldContextObject, UQuestConfig* QuestConfig);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool HasAvailableQuestsOfSameTier(UObject* WorldContextObject, UQuestConfig* InQuestConfig);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAnyActiveBossQuest();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static TArray<UQuestConfig*> GetQuestsWithPrerequisite(UObject* WorldContextObject, UQuestConfig* QuestConfig);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<EQuestState> GetQuestState(UQuestConfig* InQuestConfig);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AQuestInstance*> GetPinnedQuests() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ContainsActiveQuestOfType(UQuestConfig* QuestConfig);
    
    UFUNCTION(BlueprintCallable)
    void CompleteQuest(AQuestInstance* QuestInstance, ASimulationPlayer* SimulationPlayer, bool bIgnoreConditions);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool AreQuestPrerequisitsMet(UObject* WorldContextObject, UQuestConfig* QuestConfig);
    
    UFUNCTION(BlueprintCallable)
    AQuestInstance* AcceptQuest(UQuestConfig* QuestData, UQuestGiverSimulationComponent* QuestGiver, bool bShouldPinQuest);
    
    UFUNCTION(BlueprintCallable)
    void AcceptAutoStartQuestsIfPossible();
    
    UFUNCTION(BlueprintCallable)
    void AbortQuest(AQuestInstance* QuestInstance, ASimulationPlayer* SimulationPlayer);
    
};

