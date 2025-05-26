#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "LocSimulationSubsystem.h"
#include "ChunkPosition.h"
#include "RespawnGeneratedGridObjectsSubsystem.generated.h"

UCLASS(Blueprintable)
class LOC_API URespawnGeneratedGridObjectsSubsystem : public ULocSimulationSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed RespawnCheckInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ChunkUpdatesPerTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RespawnChanceInPercentGridObjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RespawnChanceInPercentNonGridObjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed LocalTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FChunkPosition> ChunkPositionsToUpdate;
    
    URespawnGeneratedGridObjectsSubsystem();

};

