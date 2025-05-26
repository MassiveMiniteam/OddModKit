#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BiomeGenerator.h"
#include "LandscapeLayerBasedOnHeightBiomeGenerator.generated.h"

class UGridTileLandscapeLayer;

UCLASS(Blueprintable)
class LOC_API ULandscapeLayerBasedOnHeightBiomeGenerator : public UBiomeGenerator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint HeightRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* LandscapeLayer;
    
public:
    ULandscapeLayerBasedOnHeightBiomeGenerator();

};

