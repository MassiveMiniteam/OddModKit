#pragma once
#include "CoreMinimal.h"
#include "InventoryRuleGenericItemEntry.generated.h"

class UItemConfig;

USTRUCT(BlueprintType)
struct FInventoryRuleGenericItemEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UItemConfig*> AllowedItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AllowedItemCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TargetSlotIndex;
    
    LOC_API FInventoryRuleGenericItemEntry();
};

