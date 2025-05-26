#pragma once
#include "CoreMinimal.h"
#include "TileLayerInstancedMesh.h"
#include "TileLayerInstancedMeshes.generated.h"

USTRUCT(BlueprintType)
struct FTileLayerInstancedMeshes {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, FTileLayerInstancedMesh> Meshes;
    
    LOC_API FTileLayerInstancedMeshes();
};

