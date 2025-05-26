#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "SetPlayerNumSimulationCommand.generated.h"

UCLASS(Blueprintable)
class LOCCORE_API USetPlayerNumSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 NumPlayers;
    
    USetPlayerNumSimulationCommand();

};

