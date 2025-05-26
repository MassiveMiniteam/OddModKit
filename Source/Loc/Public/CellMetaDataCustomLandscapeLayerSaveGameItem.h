#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CellMetaDataCustomLandscapeLayerSaveGameItem.generated.h"

class UGridTileLandscapeLayer;

USTRUCT(BlueprintType)
struct FCellMetaDataCustomLandscapeLayerSaveGameItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint GridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* LandscapeLayer;
    
    LOC_API FCellMetaDataCustomLandscapeLayerSaveGameItem();
};

