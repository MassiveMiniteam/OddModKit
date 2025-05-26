#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CellMetaDataCustomHeightSaveGameItem.generated.h"

USTRUCT(BlueprintType)
struct FCellMetaDataCustomHeightSaveGameItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint GridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Height;
    
    LOC_API FCellMetaDataCustomHeightSaveGameItem();
};

