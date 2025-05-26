#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "AbortQuestSimulationCommand.generated.h"

class AQuestInstance;
class ASimulationPlayer;
class UQuestManagerSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UAbortQuestSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UQuestManagerSimulationComponent* QuestManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AQuestInstance* QuestInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* SimulationPlayer;
    
    UAbortQuestSimulationCommand();

};

