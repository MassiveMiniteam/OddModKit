#pragma once
#include "CoreMinimal.h"
#include "ItemConfigCounter.generated.h"

class UItemConfig;

USTRUCT(BlueprintType)
struct FItemConfigCounter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UItemConfig* ItemConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Counter;
    
    LOC_API FItemConfigCounter();
};

