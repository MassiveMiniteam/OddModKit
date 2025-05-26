#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Fixed64Spline.h"
#include "SplinePainterStruct.generated.h"

USTRUCT(BlueprintType)
struct FSplinePainterStruct {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64Spline Spline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Color;
    
    LOC_API FSplinePainterStruct();
};

