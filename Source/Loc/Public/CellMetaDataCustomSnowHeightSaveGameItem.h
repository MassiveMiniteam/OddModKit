#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CellMetaDataCustomSnowHeightSaveGameItem.generated.h"

USTRUCT(BlueprintType)
struct FCellMetaDataCustomSnowHeightSaveGameItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint GridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 SnowHeight;
    
    LOC_API FCellMetaDataCustomSnowHeightSaveGameItem();
};

