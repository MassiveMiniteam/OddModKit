#pragma once
#include "CoreMinimal.h"
#include "NoiseGraphNodeMaster_NoiseSpawnObject.h"
#include "NoiseGraphNodeMaster_NoiseSpawnObject_CellBorder.generated.h"

class UBiomeCellConfig;
class UBiomeConfig;

UCLASS(Blueprintable)
class LOC_API UNoiseGraphNodeMaster_NoiseSpawnObject_CellBorder : public UNoiseGraphNodeMaster_NoiseSpawnObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinDistanceToEdge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoGenerateToAnotherBiome;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBiomeConfig*> BiomesToGenerateWallsTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBiomeCellConfig*> CellsToGenerateWallsTo;
    
    UNoiseGraphNodeMaster_NoiseSpawnObject_CellBorder();

};

