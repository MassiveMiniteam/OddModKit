#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "TriggerReplacementCommand.generated.h"

class ASimulationPlayer;
class UReplaceGridObjectOnConditionComponent;

UCLASS(Blueprintable)
class LOC_API UTriggerReplacementCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UReplaceGridObjectOnConditionComponent* ReplaceGridObjectComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* ExecutingPlayer;
    
    UTriggerReplacementCommand();

};

