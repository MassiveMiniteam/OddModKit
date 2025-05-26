#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CellMetaDataCustomGroundLayerSaveGameItem_New.generated.h"

class UGridTileGroundLayer;

USTRUCT(BlueprintType)
struct FCellMetaDataCustomGroundLayerSaveGameItem_New {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint GridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileGroundLayer* GroundLayer;
    
    LOC_API FCellMetaDataCustomGroundLayerSaveGameItem_New();
};

