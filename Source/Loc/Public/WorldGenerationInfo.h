#pragma once
#include "CoreMinimal.h"
#include "WorldGenerationInfo.generated.h"

class UBiomeInstance;
class UVoronoiCell;
class UVoronoiPolygon;

USTRUCT(BlueprintType)
struct FWorldGenerationInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 GenerationVersion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsDemo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UVoronoiPolygon*> VoronoiDualCells;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UVoronoiCell*> VoronoiCells;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UBiomeInstance*> BiomeInstances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UVoronoiCell* StartingCell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UBiomeInstance* VillageBiomeInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FName> VersionTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<int32> CellIdsToUnloadBecausePatched;
    
    LOC_API FWorldGenerationInfo();
};

