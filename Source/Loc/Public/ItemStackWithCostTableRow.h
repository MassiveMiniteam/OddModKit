#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemStack.h"
#include "ItemStackWithCostTableRow.generated.h"

class UUnlockableDataAsset;

USTRUCT(BlueprintType)
struct LOC_API FItemStackWithCostTableRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemStack ItemStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemStack> Cost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UUnlockableDataAsset*> Prerequisites;
    
    FItemStackWithCostTableRow();
};

