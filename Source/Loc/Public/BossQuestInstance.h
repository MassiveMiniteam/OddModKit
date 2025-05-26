#pragma once
#include "CoreMinimal.h"
#include "QuestInstance.h"
#include "BossQuestInstance.generated.h"

class UBossPhasesSimulationComponent;

UCLASS(Blueprintable)
class LOC_API ABossQuestInstance : public AQuestInstance {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBossPhasesSimulationComponent* BossPhasesSimulationComponent;
    
public:
    ABossQuestInstance(const FObjectInitializer& ObjectInitializer);

};

