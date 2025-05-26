#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SerializedSimulationObject.h"
#include "ChunkPosition.h"
#include "GridCell.h"
#include "GridChunk.generated.h"

class UChunkSpawnerSimulationComponent;

UCLASS(Blueprintable)
class UGridChunk : public USerializedSimulationObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FChunkPosition ChunkPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint ChunkGridOrigin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGridCell> Cells;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DistanceToLocalPlayerChunk;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UChunkSpawnerSimulationComponent*> ChunkLoader;
    
    UGridChunk();

};

