#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "PlayerLeftEventSimulationCommand.generated.h"

class ASimulationPlayer;

UCLASS(Blueprintable)
class LOC_API UPlayerLeftEventSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* SimulationPlayer;
    
    UPlayerLeftEventSimulationCommand();

};

