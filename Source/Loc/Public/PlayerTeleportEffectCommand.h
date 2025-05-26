#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimulationCommand.h"
#include "PlayerTeleportEffectCommand.generated.h"

class ASimulationPlayer;

UCLASS(Blueprintable)
class LOC_API UPlayerTeleportEffectCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* SimulationPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntVector TargetLocation;
    
    UPlayerTeleportEffectCommand();

};

