#pragma once
#include "CoreMinimal.h"
#include "NoiseSpawnObjectGroundTypeItem.generated.h"

class AActor;
class UGridTileGroundLayer;
class UGroundMeshMappingAsset;

USTRUCT(BlueprintType)
struct FNoiseSpawnObjectGroundTypeItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileGroundLayer* Layer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> ActorsToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGroundMeshMappingAsset* GroundMeshMappingAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFlipGroundLayerCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyOnNoLandscapeLayer;
    
    LOC_API FNoiseSpawnObjectGroundTypeItem();
};

