#pragma once
#include "CoreMinimal.h"
#include "GridTileLayerAsset.h"
#include "GridTileGroundLayer.generated.h"

class UGridTileGroundLayer;
class UMaterialInstance;

UCLASS(Blueprintable)
class LOC_API UGridTileGroundLayer : public UGridTileLayerAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstance*> TransitionMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGridTileGroundLayer*> TransitionTilesToNeighbour;
    
    UGridTileGroundLayer();

};

