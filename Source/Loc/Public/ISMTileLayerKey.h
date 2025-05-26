#pragma once
#include "CoreMinimal.h"
#include "ISMTileLayerKey.generated.h"

class UGridTileLayerAsset;
class UStaticMesh;

USTRUCT(BlueprintType)
struct FISMTileLayerKey {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> StaticMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLayerAsset* Layer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLayerAsset* LandscapeLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Identifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWithPhysics;
    
    LOC_API FISMTileLayerKey();
};
FORCEINLINE uint32 GetTypeHash(const FISMTileLayerKey) { return 0; }

