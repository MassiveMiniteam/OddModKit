#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "PlayerInteractionData.h"
#include "SetInteractingPlayerCommand.generated.h"

class ASimulationActor;

UCLASS(Blueprintable)
class LOC_API USetInteractingPlayerCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FPlayerInteractionData PlayerInteractionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationActor* Actor;
    
    USetInteractingPlayerCommand();

};

