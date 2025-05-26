#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "RemoveInteractingPlayerCommand.generated.h"

class ASimulationActor;
class ASimulationPlayer;

UCLASS(Blueprintable)
class LOC_API URemoveInteractingPlayerCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* Player;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationActor* Actor;
    
    URemoveInteractingPlayerCommand();

};

