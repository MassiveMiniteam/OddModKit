#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "PinQuestSimulationCommand.generated.h"

class AQuestInstance;
class UQuestManagerSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UPinQuestSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UQuestManagerSimulationComponent* QuestManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AQuestInstance* QuestInstance;
    
    UPinQuestSimulationCommand();

};

