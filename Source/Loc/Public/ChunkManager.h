#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "ChunkPosition.h"
#include "ChunkManager.generated.h"

class AGrid;
class ASimulationManager;
class UBiomeCellConfig;
class UGridChunk;
class UWorldGenerator;

UCLASS(Blueprintable)
class LOC_API UChunkManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FChunkPosition, UGridChunk*> Chunks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FChunkPosition> ChunkPositions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGrid* Grid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorldGenerator* WorldGenerator;
    
    UChunkManager();

private:
    UFUNCTION(BlueprintCallable)
    void OnSimulation(ASimulationManager* SimulationManager);
    
public:
    UFUNCTION(BlueprintCallable)
    UGridChunk* LoadChunk(const FChunkPosition& ChunkPosition);
    
    UFUNCTION(BlueprintCallable)
    void GetPositionsForBiomeCellConfig(UBiomeCellConfig* BiomeCellConfig, TArray<FIntPoint>& OutPositions);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FChunkPosition GetChunkPositionForPosition(const FIntPoint& position) const;
    
    UFUNCTION(BlueprintCallable)
    FIntPoint GetChunkGridOrigin(FChunkPosition ChunkPosition);
    
    UFUNCTION(BlueprintCallable)
    UGridChunk* GetChunkAtGridPosition(const FIntPoint& GridPosition);
    
};

