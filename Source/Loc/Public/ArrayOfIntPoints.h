#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ArrayOfIntPoints.generated.h"

USTRUCT(BlueprintType)
struct FArrayOfIntPoints {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> Array;
    
    LOC_API FArrayOfIntPoints();
};

