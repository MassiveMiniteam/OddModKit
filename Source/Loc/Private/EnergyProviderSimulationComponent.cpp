#include "EnergyProviderSimulationComponent.h"

UEnergyProviderSimulationComponent::UEnergyProviderSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanEverTick = true;
    this->bConsumeItemsOverTime = false;
    this->ConsumeRate = 10;
    this->ConsumeRateCounter = 0;
}

bool UEnergyProviderSimulationComponent::IsProvidingEnergy() {
    return false;
}


