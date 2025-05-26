#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "DisableInteractionUntilCommandIsExecutedCommand.generated.h"

class ASimulationActor;

UCLASS(Blueprintable)
class LOC_API UDisableInteractionUntilCommandIsExecutedCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationActor* SimulationActor;
    
    UDisableInteractionUntilCommandIsExecutedCommand();

};

