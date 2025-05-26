#pragma once
#include "CoreMinimal.h"
#include "BiomeGenerator.h"
#include "CliffBiomeGenerator.generated.h"

class ASimulationActor;
class UGridTileLandscapeLayer;

UCLASS(Blueprintable)
class LOC_API UCliffBiomeGenerator : public UBiomeGenerator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<ASimulationActor>> SmallCliffActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<ASimulationActor>> HighCliffActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* LandscapeLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CliffChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CliffPropagationChance;
    
public:
    UCliffBiomeGenerator();

};

