#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ChunkSpawnerSimulationComponent.h"
#include "ChunkSpawnerAllBiomeCellsOfTypeSimulationComponent.generated.h"

class UBiomeCellConfig;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UChunkSpawnerAllBiomeCellsOfTypeSimulationComponent : public UChunkSpawnerSimulationComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBiomeCellConfig*> BiomeCellConfigs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint LoadSizeAroundCenter;
    
public:
    UChunkSpawnerAllBiomeCellsOfTypeSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

