#include "ItemStackingStrategy.h"

UItemStackingStrategy::UItemStackingStrategy() {
    this->bShouldPlayGrowAnimation = false;
}

TSoftObjectPtr<UStaticMesh> UItemStackingStrategy::CalcStackLayout_Implementation(const UItemConfig* ItemConfig, int32 Amount) const {
    return NULL;
}


