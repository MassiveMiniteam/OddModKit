#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CellMetaDataCustomHeightSaveGameItem_New.generated.h"

USTRUCT(BlueprintType)
struct FCellMetaDataCustomHeightSaveGameItem_New {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint GridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Height;
    
    LOC_API FCellMetaDataCustomHeightSaveGameItem_New();
};

