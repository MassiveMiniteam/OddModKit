#pragma once
#include "CoreMinimal.h"
#include "Fixed64.h"
#include "ChargeLevel.generated.h"

USTRUCT(BlueprintType)
struct FChargeLevel {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Threshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64 ScoreDecay;
    
    LOC_API FChargeLevel();
};

