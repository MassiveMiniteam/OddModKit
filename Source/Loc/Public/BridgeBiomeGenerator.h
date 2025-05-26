#pragma once
#include "CoreMinimal.h"
#include "BiomeGenerator.h"
#include "BridgeBiomeGenerator.generated.h"

class ASimulationActor;
class UGridTileLandscapeLayer;

UCLASS(Blueprintable)
class LOC_API UBridgeBiomeGenerator : public UBiomeGenerator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ASimulationActor> BridgeActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* LandscapeLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinimumHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinimumDeep;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaximumHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BridgeDistance;
    
public:
    UBridgeBiomeGenerator();

};

