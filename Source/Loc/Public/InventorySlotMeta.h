#pragma once
#include "CoreMinimal.h"
#include "InventorySlotMeta.generated.h"

class UItemConfig;

USTRUCT(BlueprintType)
struct FInventorySlotMeta {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 SlotIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UItemConfig* LastItemConfig;
    
    LOC_API FInventorySlotMeta();
};

