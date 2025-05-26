#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ShopItemTableRow.h"
#include "SingleShopItemConfig.generated.h"

class UDataTable;

UCLASS(Blueprintable)
class LOC_API USingleShopItemConfig : public UDataAsset {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* TargetDataTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RowName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FShopItemTableRow Part;
    
public:
    USingleShopItemConfig();

    UFUNCTION(BlueprintCallable)
    void Unload();
    
    UFUNCTION(BlueprintCallable)
    void Load();
    
};

