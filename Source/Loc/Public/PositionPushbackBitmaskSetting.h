#pragma once
#include "CoreMinimal.h"
#include "EPositionPushbackType.h"
#include "PositionPushbackBitmaskSetting.generated.h"

USTRUCT(BlueprintType)
struct FPositionPushbackBitmaskSetting {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EPositionPushbackType> BitmaskEnums;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 BitMask;
    
    LOC_API FPositionPushbackBitmaskSetting();
};

