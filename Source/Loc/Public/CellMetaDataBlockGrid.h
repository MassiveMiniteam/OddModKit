#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CellMetaDataBlockGrid.generated.h"

USTRUCT(BlueprintType)
struct FCellMetaDataBlockGrid {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint BlockedBySpawnedObjectPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bMapsToSpawnedObject;
    
    LOC_API FCellMetaDataBlockGrid();
};

