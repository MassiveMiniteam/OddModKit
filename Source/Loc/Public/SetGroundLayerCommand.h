#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimulationCommand.h"
#include "Templates/SubclassOf.h"
#include "SetGroundLayerCommand.generated.h"

class AGrid;
class ASimulationPlayer;
class UConstructableFloorTilesSubsystem;
class UConstructableGroundTileConfig;
class UGridPlacementRuleConfig;

UCLASS(Blueprintable)
class LOC_API USetGroundLayerCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AGrid* Grid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> DraggedTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UConstructableGroundTileConfig* ConstructableGroundTileConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* ExecutingPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGridPlacementRuleConfig>> PlacementRulesToConsider;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConstructableFloorTilesSubsystem* ConstructableFloorsSubsystem;
    
public:
    USetGroundLayerCommand();

};

