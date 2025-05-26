#pragma once
#include "CoreMinimal.h"
#include "Fixed64Vector.h"
#include "Fixed64SplinePoint.generated.h"

USTRUCT(BlueprintType)
struct MMTFIXED64_API FFixed64SplinePoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64Vector Position;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64Vector TangentIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64Vector TangentOut;
    
    FFixed64SplinePoint();
};

