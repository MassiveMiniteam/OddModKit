#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "QuestToastsSubsystem.generated.h"

class AQuestInstance;
class ASimulationPlayer;
class UQuestConfig;
class UQuestManagerSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UQuestToastsSubsystem : public UWorldSubsystem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQuestManagerSimulationComponent* QuestManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UQuestConfig*> CompletedQuestConfigsQueue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UQuestConfig*> AcceptedQuestConfigsQueue;
    
public:
    UQuestToastsSubsystem();

    UFUNCTION(BlueprintCallable)
    void UnregisterQuestManager(UQuestManagerSimulationComponent* InQuestManager);
    
    UFUNCTION(BlueprintCallable)
    void RegisterQuestManager(UQuestManagerSimulationComponent* InQuestManager);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnQuestCompleted(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* QuestInstance, ASimulationPlayer* SimulationPlayer);
    
    UFUNCTION(BlueprintCallable)
    void OnQuestAccepted(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* QuestInstance);
    
    UFUNCTION(BlueprintCallable)
    UQuestConfig* DequeueCompletedQuest(bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    UQuestConfig* DequeueAcceptedQuest(bool& bSuccess);
    
};

