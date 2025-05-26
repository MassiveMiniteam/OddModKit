#include "GridTileLayerAsset.h"

UGridTileLayerAsset::UGridTileLayerAsset() {
    this->bDrawMapBlackOnHighLevels = false;
    this->HeightTreshold = 4;
    this->MapID = 0;
    this->NumCustomPrimitiveData = 0;
}

void UGridTileLayerAsset::ApplyLandscapeMaterialToStaticMesh(UStaticMeshComponent* StaticMeshComponent) {
}


