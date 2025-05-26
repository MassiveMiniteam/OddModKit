#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "IntPointToConstructableConfig.h"
#include "Templates/SubclassOf.h"
#include "PlaceGridNetworkActorCommand.generated.h"

class ASimulationPlayer;
class UGridNetworkManagerSubsystem;

UCLASS(Blueprintable)
class LOC_API UPlaceGridNetworkActorCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FIntPointToConstructableConfig> DraggedTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGridNetworkManagerSubsystem> GridNetworkManagerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* ExecutingSimulationPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIgnoreCost;
    
    UPlaceGridNetworkActorCommand();

};

