#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimulationCommand.h"
#include "MapTeleportDoneEffectCommand.generated.h"

class ASimulationActor;

UCLASS(Blueprintable)
class LOC_API UMapTeleportDoneEffectCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint TargetGridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationActor* TeleportedActor;
    
    UMapTeleportDoneEffectCommand();

};

