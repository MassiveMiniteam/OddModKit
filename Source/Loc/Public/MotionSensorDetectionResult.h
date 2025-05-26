#pragma once
#include "CoreMinimal.h"
#include "MotionSensorDetectionResult.generated.h"

class ASimulationActor;

USTRUCT(BlueprintType)
struct FMotionSensorDetectionResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASimulationActor*> DetectedActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDetected;
    
    LOC_API FMotionSensorDetectionResult();
};

