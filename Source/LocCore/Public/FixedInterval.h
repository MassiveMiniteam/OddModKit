#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "FixedInterval.generated.h"

USTRUCT(BlueprintType)
struct FFixedInterval {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed min;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed max;
    
    LOCCORE_API FFixedInterval();
};

