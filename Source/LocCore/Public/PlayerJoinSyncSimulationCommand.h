#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "PlayerJoinSyncSimulationCommand.generated.h"

UCLASS(Blueprintable)
class LOCCORE_API UPlayerJoinSyncSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPlayerJoinSyncSimulationCommand();

};

