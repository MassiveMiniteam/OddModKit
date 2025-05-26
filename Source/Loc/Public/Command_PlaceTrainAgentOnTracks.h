#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "TrainTrackLocation.h"
#include "Command_PlaceTrainAgentOnTracks.generated.h"

class UConstructableConfig;
class UInventoryComponent;
class UTrainTracksAgentSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UCommand_PlaceTrainAgentOnTracks : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UConstructableConfig* Config;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UTrainTracksAgentSimulationComponent* AgentAttachedTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FTrainTrackLocation Location;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UInventoryComponent* PlayerInventory;
    
    UCommand_PlaceTrainAgentOnTracks();

};

