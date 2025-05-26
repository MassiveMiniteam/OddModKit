#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CellMetaDataBlockGrid.h"
#include "CellMetaDataBlockGridSaveGameItem_New.generated.h"

USTRUCT(BlueprintType)
struct FCellMetaDataBlockGridSaveGameItem_New {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint GridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCellMetaDataBlockGrid CellMetaData;
    
    LOC_API FCellMetaDataBlockGridSaveGameItem_New();
};

