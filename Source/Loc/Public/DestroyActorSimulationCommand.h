#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "DestroyActorSimulationCommand.generated.h"

class ASimulationActor;

UCLASS(Blueprintable)
class LOC_API UDestroyActorSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationActor* SimulationActor;
    
    UDestroyActorSimulationCommand();

};

