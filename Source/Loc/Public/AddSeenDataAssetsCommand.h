#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "AddSeenDataAssetsCommand.generated.h"

class UDataAsset;
class URecentlyUnlockedAssetsTrackerSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UAddSeenDataAssetsCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    URecentlyUnlockedAssetsTrackerSimulationComponent* RecentlyUnlockedTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UDataAsset*> SeenDataAssets;
    
    UAddSeenDataAssetsCommand();

};

