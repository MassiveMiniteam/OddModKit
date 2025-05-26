#pragma once
#include "CoreMinimal.h"
#include "BiomeGenerator.h"
#include "WaterFillBiomeGenerator.generated.h"

class UGridTileLandscapeLayer;

UCLASS(Blueprintable)
class LOC_API UWaterFillBiomeGenerator : public UBiomeGenerator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* WaterLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WaterFillHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OverrideHeight;
    
public:
    UWaterFillBiomeGenerator();

};

