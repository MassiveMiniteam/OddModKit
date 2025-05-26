#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "QuestGiverOnFinish_DebugCommand.generated.h"

class UQuestGiverSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UQuestGiverOnFinish_DebugCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UQuestGiverSimulationComponent* QuestGiver;
    
    UQuestGiverOnFinish_DebugCommand();

};

