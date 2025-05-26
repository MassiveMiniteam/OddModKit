#include "ElementDataAsset.h"

UElementDataAsset::UElementDataAsset() {
    this->DefaultInteraction = EElementInteractionBehavior::Block;
    this->SourceEqualTargetInteraction = EElementInteractionBehavior::AddIntensity;
    this->DefaultGameplayEffectClass = NULL;
    this->bDecaysIfNotNaturalElement = true;
}


