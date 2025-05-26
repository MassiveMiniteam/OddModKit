#pragma once
#include "CoreMinimal.h"
#include "IntPointToConstructableConfig.h"
#include "GridNetworkCopyData.generated.h"

class UActorPoolManager;
class UGridNetworkManagerSubsystem;

USTRUCT(BlueprintType)
struct FGridNetworkCopyData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPointToConstructableConfig> DraggedTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridNetworkManagerSubsystem* GridNetworkManagerSubsystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RotationRelative;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActorPoolManager* InvalidTilePreviewPool;
    
    LOC_API FGridNetworkCopyData();
};

