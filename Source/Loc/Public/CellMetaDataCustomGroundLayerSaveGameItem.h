#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CellMetaDataCustomGroundLayerSaveGameItem.generated.h"

class UGridTileGroundLayer;

USTRUCT(BlueprintType)
struct FCellMetaDataCustomGroundLayerSaveGameItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint GridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UGridTileGroundLayer* GroundLayer;
    
    LOC_API FCellMetaDataCustomGroundLayerSaveGameItem();
};

