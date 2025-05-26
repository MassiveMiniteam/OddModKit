#include "ItemStackingStrategy.h"

UItemStackingStrategy::UItemStackingStrategy() {
    this->bShouldPlayGrowAnimation = false;
}

FStaticMeshAndTransforms UItemStackingStrategy::CalcStackLayout_Implementation(const UItemConfig* ItemConfig, int32 Amount) const {
    return FStaticMeshAndTransforms{};
}


