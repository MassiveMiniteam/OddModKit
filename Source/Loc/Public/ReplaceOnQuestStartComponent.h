#pragma once
#include "CoreMinimal.h"
#include "ReplaceSimulationComponent.h"
#include "ReplaceOnQuestStartComponent.generated.h"

class AQuestInstance;
class UQuestConfig;
class UQuestManagerSimulationComponent;
class UUnlockableDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UReplaceOnQuestStartComponent : public UReplaceSimulationComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UQuestConfig* QuestConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQuestManagerSimulationComponent* QuestManager;
    
public:
    UReplaceOnQuestStartComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnNewQuestAccepted(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* QuestInstance);
    
    UFUNCTION(BlueprintCallable)
    void OnItemUnlocked(UUnlockableDataAsset* UnlockableDataAsset);
    
};

