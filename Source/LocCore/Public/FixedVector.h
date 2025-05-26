#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "FixedVector.generated.h"

USTRUCT(BlueprintType)
struct FFixedVector {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed X;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Y;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Z;
    
    LOCCORE_API FFixedVector();
};

