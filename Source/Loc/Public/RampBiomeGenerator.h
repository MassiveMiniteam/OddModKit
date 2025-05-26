#pragma once
#include "CoreMinimal.h"
#include "BiomeGenerator.h"
#include "RampBiomeGenerator.generated.h"

class ASimulationActor;
class UGridTileLandscapeLayer;

UCLASS(Blueprintable)
class LOC_API URampBiomeGenerator : public UBiomeGenerator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ASimulationActor> RampActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* LandscapeLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinimumCliffSideLength;
    
public:
    URampBiomeGenerator();

};

