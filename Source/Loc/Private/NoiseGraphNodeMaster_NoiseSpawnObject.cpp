#include "NoiseGraphNodeMaster_NoiseSpawnObject.h"

UNoiseGraphNodeMaster_NoiseSpawnObject::UNoiseGraphNodeMaster_NoiseSpawnObject() {
    this->bRandomRotation = true;
    this->FreeSpaceNeededRadius = 1;
    this->bReduceChanceInFlatSeed = false;
    this->ReduceChanceToInFlatSeed = 10;
    this->bDistributeLandscapeLayerUnderneath = false;
    this->LandscapeLayerToDistribute = NULL;
    this->bAllowSpawnOnDifferentHeights = false;
    this->bAllowCustomLandscapeLayer = false;
    this->bAllowCliff = false;
}


