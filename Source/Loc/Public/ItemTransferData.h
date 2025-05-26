#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "ItemStack.h"
#include "ItemTransferData.generated.h"

USTRUCT(BlueprintType)
struct FItemTransferData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed ElapsedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FItemStack ItemStack;
    
    LOC_API FItemTransferData();
};

