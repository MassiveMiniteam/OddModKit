#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CellMetaDataCustomLandscapeLayerSaveGameItem_New.generated.h"

class UGridTileLandscapeLayer;

USTRUCT(BlueprintType)
struct FCellMetaDataCustomLandscapeLayerSaveGameItem_New {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint GridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* LandscapeLayer;
    
    LOC_API FCellMetaDataCustomLandscapeLayerSaveGameItem_New();
};

