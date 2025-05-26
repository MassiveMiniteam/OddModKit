#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CellMetaDataSpawnActor.h"
#include "CellMetaDataSpawnActorSaveGameItem_New.generated.h"

USTRUCT(BlueprintType)
struct FCellMetaDataSpawnActorSaveGameItem_New {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint GridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCellMetaDataSpawnActor CellMetaData;
    
    LOC_API FCellMetaDataSpawnActorSaveGameItem_New();
};

