#include "PathAddOn_ApplyGameplayEffect_SimulationComponent.h"

UPathAddOn_ApplyGameplayEffect_SimulationComponent::UPathAddOn_ApplyGameplayEffect_SimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bApplyOnlyIfDirectionMatches = true;
    this->bApplyOnEntering = true;
    this->EffectClass = NULL;
}


