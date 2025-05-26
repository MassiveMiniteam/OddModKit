#include "DiggableSimulationComponent.h"

UDiggableSimulationComponent::UDiggableSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DamageEffectClass = NULL;
    this->bUseSpreading = false;
    this->MyDamageIndex = 0;
    this->Targeting = NULL;
}

void UDiggableSimulationComponent::ApplySpreadingDamage(int32 Index) {
}


