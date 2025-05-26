#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "EMapIconInteractionType.h"
#include "InteractFromWorldmapCommand.generated.h"

class ASimulationPlayer;
class UMapIconSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UInteractFromWorldmapCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* SimulationPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UMapIconSimulationComponent* MapIconComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EMapIconInteractionType MapInteractionType;
    
    UInteractFromWorldmapCommand();

};

