#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemStack.h"
#include "ItemLootTableRow.generated.h"

USTRUCT(BlueprintType)
struct FItemLootTableRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Percentage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemStack> Items;
    
    LOC_API FItemLootTableRow();
};

