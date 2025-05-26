#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CellMetaDataCustomSnowHeightSaveGameItem_New.generated.h"

USTRUCT(BlueprintType)
struct FCellMetaDataCustomSnowHeightSaveGameItem_New {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint GridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 SnowHeight;
    
    LOC_API FCellMetaDataCustomSnowHeightSaveGameItem_New();
};

