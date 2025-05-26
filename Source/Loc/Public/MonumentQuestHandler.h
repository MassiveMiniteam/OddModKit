#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "MonumentQuestHandler.generated.h"

class UQuestGiverSimulationComponent;
class UQuestManagerSimulationComponent;
class UUnlockHandlingSimulationComponent;
class UUnlockableDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMonumentQuestHandler : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUnlockHandlingSimulationComponent* UnlockHandler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQuestGiverSimulationComponent* QuestGiverComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQuestManagerSimulationComponent* QuestManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRefreshAvailableQuestsNextTick;
    
public:
    UMonumentQuestHandler(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnItemUnlocked(UUnlockableDataAsset* UnlockableDataAsset);
    
};

