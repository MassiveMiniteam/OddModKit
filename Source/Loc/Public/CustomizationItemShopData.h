#pragma once
#include "CoreMinimal.h"
#include "UnlockableDataAsset.h"
#include "CustomizationItemShopData.generated.h"

class UTexture2D;

UCLASS(Blueprintable)
class LOC_API UCustomizationItemShopData : public UUnlockableDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DetailText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Icon;
    
    UCustomizationItemShopData();

};

