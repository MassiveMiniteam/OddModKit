#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CellMetaDataBlockGrid.h"
#include "CellMetaDataBlockGridSaveGameItem.generated.h"

USTRUCT(BlueprintType)
struct FCellMetaDataBlockGridSaveGameItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint GridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FCellMetaDataBlockGrid CellMetaData;
    
    LOC_API FCellMetaDataBlockGridSaveGameItem();
};

