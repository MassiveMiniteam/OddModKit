#pragma once
#include "CoreMinimal.h"
#include "IntPointToConstructableConfig.h"
#include "Templates/SubclassOf.h"
#include "GridNetworkPlacementData.generated.h"

class ASimulationPlayer;
class UGridNetworkManagerSubsystem;

USTRUCT(BlueprintType)
struct FGridNetworkPlacementData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPointToConstructableConfig> DraggedTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGridNetworkManagerSubsystem> GridNetworkManagerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* ExecutingSimulationPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnorePlacementRules;
    
    LOC_API FGridNetworkPlacementData();
};

