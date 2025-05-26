#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CellMetaDataSpawnActor.h"
#include "CellMetaDataSpawnActorSaveGameItem.generated.h"

USTRUCT(BlueprintType)
struct FCellMetaDataSpawnActorSaveGameItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint GridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FCellMetaDataSpawnActor CellMetaData;
    
    LOC_API FCellMetaDataSpawnActorSaveGameItem();
};

