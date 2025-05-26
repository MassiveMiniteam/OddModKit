#pragma once
#include "CoreMinimal.h"
#include "ISMTileLayerKey.h"
#include "TileLayerInstancedMesh.generated.h"

USTRUCT(BlueprintType)
struct FTileLayerInstancedMesh {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FISMTileLayerKey Key;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Index;
    
    LOC_API FTileLayerInstancedMesh();
};

