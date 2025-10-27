#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LocSimulationSubsystem.h"
#include "ConstructableFloorSubsystemDelegateDelegate.h"
#include "ConstructableFloorSubsystemDelegate_OnlyPlayerDelegate.h"
#include "ConstructableFloorTilesSubsystem.generated.h"

class UConstructableGroundTileConfig;
class UGridTileGroundLayer;

UCLASS(Blueprintable)
class LOC_API UConstructableFloorTilesSubsystem : public ULocSimulationSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConstructableFloorSubsystemDelegate OnTileUpdatedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConstructableFloorSubsystemDelegate_OnlyPlayer OnRefreshCalledWithoutValidTileChangeDelegate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, int32> PositionToOriginalGroundTileMapping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UGridTileGroundLayer>> IndexToGroundTileMapping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UConstructableGroundTileConfig*> GroundTileConfigs;
    
public:
    UConstructableFloorTilesSubsystem();

};

