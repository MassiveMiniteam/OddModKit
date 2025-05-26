#pragma once
#include "CoreMinimal.h"
#include "Fixed64.h"
#include "Fixed64SplineSegmentLocation.generated.h"

USTRUCT(BlueprintType)
struct MMTFIXED64_API FFixed64SplineSegmentLocation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SegmentIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64 RelativeDistanceAlongSegment;
    
    FFixed64SplineSegmentLocation();
};

