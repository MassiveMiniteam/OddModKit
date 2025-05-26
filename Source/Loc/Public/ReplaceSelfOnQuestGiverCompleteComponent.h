#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "ReplaceSelf_QuestGiver_QuestInstance_SimulationPlayer_EventDelegate.h"
#include "Templates/SubclassOf.h"
#include "ReplaceSelfOnQuestGiverCompleteComponent.generated.h"

class AGridObject;
class AQuestInstance;
class ASimulationPlayer;
class UQuestGiverSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UReplaceSelfOnQuestGiverCompleteComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FReplaceSelf_QuestGiver_QuestInstance_SimulationPlayer_Event OnBeforeReplaceSelf;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQuestGiverSimulationComponent* QuestGiverComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AGridObject> ReplacingClass;
    
public:
    UReplaceSelfOnQuestGiverCompleteComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void Unlock_Debug();
    
    UFUNCTION(BlueprintCallable)
    void OnQuestCompleted(UQuestGiverSimulationComponent* QuestGiver, AQuestInstance* QuestInstance, ASimulationPlayer* SimulationPlayer);
    
};

