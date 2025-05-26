#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemStack.h"
#include "ShopItemTableRow.generated.h"

class UDataTable;
class UUnlockableDataAsset;

USTRUCT(BlueprintType)
struct LOC_API FShopItemTableRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUnlockableDataAsset* ShopItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemStack> Cost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UUnlockableDataAsset*> Prerequisites;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* RelatedDataTable;
    
    FShopItemTableRow();
};

