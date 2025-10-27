#pragma once
#include "CoreMinimal.h"
#include "WireLessLogicChannel.generated.h"

class UItemConfig;
class UItemStackData;

USTRUCT(BlueprintType)
struct FWireLessLogicChannel {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemConfig* Config;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemStackData* Data;
    
    LOC_API FWireLessLogicChannel();
};

