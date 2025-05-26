#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "UnpinQuestSimulationCommand.generated.h"

class AQuestInstance;
class UQuestManagerSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UUnpinQuestSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UQuestManagerSimulationComponent* QuestManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AQuestInstance* QuestInstance;
    
    UUnpinQuestSimulationCommand();

};

