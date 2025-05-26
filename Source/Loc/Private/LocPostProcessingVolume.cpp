#include "LocPostProcessingVolume.h"

ALocPostProcessingVolume::ALocPostProcessingVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CurrentWeight = 0.00f;
    this->LightPreset = NULL;
}

void ALocPostProcessingVolume::SetWeight(float Weight) {
}



