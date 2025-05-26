#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "MapIconInteractionTrackingCommand.generated.h"

class UMapIconSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UMapIconInteractionTrackingCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UMapIconSimulationComponent* MapIconSimulationComponent;
    
    UMapIconInteractionTrackingCommand();

};

