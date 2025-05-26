#pragma once
#include "CoreMinimal.h"
#include "BiomeGenerator.h"
#include "VillageLandscapeBiomeGenerator.generated.h"

class UGridTileLandscapeLayer;
class UVillageLandscapeData;

UCLASS(Blueprintable)
class LOC_API UVillageLandscapeBiomeGenerator : public UBiomeGenerator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UVillageLandscapeData* VillageLandscapeData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* WaterLandscapeLayer;
    
public:
    UVillageLandscapeBiomeGenerator();

};

