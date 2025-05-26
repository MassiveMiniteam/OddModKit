#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "TrackInteractionCommand.generated.h"

class ASimulationActor;

UCLASS(Blueprintable)
class LOC_API UTrackInteractionCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationActor* SimulationActor;
    
    UTrackInteractionCommand();

};

