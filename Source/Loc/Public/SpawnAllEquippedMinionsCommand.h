#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "SpawnAllEquippedMinionsCommand.generated.h"

class UMinionControllerSimulationBaseComponent;

UCLASS(Blueprintable)
class LOC_API USpawnAllEquippedMinionsCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UMinionControllerSimulationBaseComponent* MinionController;
    
    USpawnAllEquippedMinionsCommand();

};

