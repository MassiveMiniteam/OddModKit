#pragma once
#include "CoreMinimal.h"
#include "NoiseGraphNodeMaster_NoiseSpawnBase.h"
#include "NoiseGraphNodeMaster_CellBorderNoise.generated.h"

class UBiomeCellConfig;

UCLASS(Blueprintable)
class LOC_API UNoiseGraphNodeMaster_CellBorderNoise : public UNoiseGraphNodeMaster_NoiseSpawnBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TargetHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinDistanceToEdge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoGenerateToAnotherBiome;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBiomeCellConfig*> CellsToGenerateWallsTo;
    
public:
    UNoiseGraphNodeMaster_CellBorderNoise();

};

