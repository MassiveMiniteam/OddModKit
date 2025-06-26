#pragma once
#include "CoreMinimal.h"
#include "ItemStack.h"
#include "BaseItemTagItemPair.generated.h"

USTRUCT(BlueprintType)
struct FBaseItemTagItemPair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemStack BaseOutputItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemStack TagOutputItem;
    
    LOC_API FBaseItemTagItemPair();
};

