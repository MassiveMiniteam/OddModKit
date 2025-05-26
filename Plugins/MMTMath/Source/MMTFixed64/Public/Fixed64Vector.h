#pragma once
#include "CoreMinimal.h"
#include "Fixed64.h"
#include "Fixed64Vector.generated.h"

USTRUCT(BlueprintType)
struct MMTFIXED64_API FFixed64Vector {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64 X;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64 Y;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64 Z;
    
    FFixed64Vector();
};

