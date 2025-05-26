#pragma once
#include "CoreMinimal.h"
#include "ItemStack.generated.h"

class UItemConfig;
class UItemStackData;

USTRUCT(BlueprintType)
struct FItemStack {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UItemConfig* Config;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Amount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UItemStackData* Data;
    
    LOC_API FItemStack();
};

