#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SimulationActorComponent.h"
#include "EQuestState.h"
#include "QuestGiver_QuestConfigArray_QuestInstaceArray_EventDelegate.h"
#include "QuestGiver_Quest_Player_EventDelegate.h"
#include "QuestGiverSimulationComponent.generated.h"

class AQuestInstance;
class ASimulationPlayer;
class UInventoryComponent;
class UQuestConfig;
class UQuestManagerSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UQuestGiverSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestGiver_QuestConfigArray_QuestInstaceArray_Event OnQuestListUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestGiver_Quest_Player_Event OnQuestFinished;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQuestManagerSimulationComponent* QuestManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference QuestGiverInventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* QuestInventory;
    
public:
    UQuestGiverSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnQuestListChanged(UQuestManagerSimulationComponent* QuestManagerSimulationComponent);
    
    UFUNCTION(BlueprintCallable)
    void OnQuestCompleted(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* QuestInstance, ASimulationPlayer* SimulationPlayer);
    
    UFUNCTION(BlueprintCallable)
    void OnQuestAborted(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* QuestInstance, ASimulationPlayer* SimulationPlayer);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasActiveQuestOfType(UQuestConfig* QuestConfig);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<EQuestState> GetQuestStateForQuestGiver(UQuestConfig* InQuestConfig);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetQuestInventory() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AQuestInstance* GetQuestInstanceOfType(UQuestConfig* QuestConfig);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AQuestInstance*> GetCompletableQuests(ASimulationPlayer* SimulationPlayer);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetAvailableQuestsAsDebugString();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UQuestConfig*> GetAvailableQuests(bool bIgnorePrerequisitesAndDisqualifiers);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UQuestConfig*> GetAllQuestsForNPC();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AQuestInstance*> GetActiveQuests();
    
    UFUNCTION(BlueprintCallable)
    void ForceCallOnFinished();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanCompleteAnyQuest(ASimulationPlayer* SimulationPlayer);
    
};

