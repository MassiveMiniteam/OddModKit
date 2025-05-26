#pragma once
#include "CoreMinimal.h"
#include "NoiseSpawnGroundMeshGroundTypeItem.generated.h"

class UGridTileGroundLayer;
class UGroundMeshMappingAsset;

USTRUCT(BlueprintType)
struct FNoiseSpawnGroundMeshGroundTypeItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileGroundLayer* Layer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGroundMeshMappingAsset* GroundMeshMappingAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFlipGroundLayerCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyOnNoLandscapeLayer;
    
    LOC_API FNoiseSpawnGroundMeshGroundTypeItem();
};

