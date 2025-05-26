#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "RemoveRecentlyUnlockedDataAssetsCommand.generated.h"

class UDataAsset;
class URecentlyUnlockedAssetsTrackerSimulationComponent;

UCLASS(Blueprintable)
class LOC_API URemoveRecentlyUnlockedDataAssetsCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    URecentlyUnlockedAssetsTrackerSimulationComponent* RecentlyUnlockedTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UDataAsset*> RecentlyUnlockedAssets;
    
    URemoveRecentlyUnlockedDataAssetsCommand();

};

