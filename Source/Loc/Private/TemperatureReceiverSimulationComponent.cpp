#include "TemperatureReceiverSimulationComponent.h"

UTemperatureReceiverSimulationComponent::UTemperatureReceiverSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->EfficiencyConfig = NULL;
    this->RecipesComponent = NULL;
}

void UTemperatureReceiverSimulationComponent::OnRecipeChanged(USelectableRecipesSimulationComponent* Component, URecipeConfig* Config) {
}

FInt32Interval UTemperatureReceiverSimulationComponent::GetOptimalEfficiencyRange() const {
    return FInt32Interval{};
}

UTemperatureEfficiencyConfig* UTemperatureReceiverSimulationComponent::GetDefaultTemperatureEfficiencyConfig() const {
    return NULL;
}

int32 UTemperatureReceiverSimulationComponent::GetCurrentTemperature() const {
    return 0;
}

UTemperatureEfficiencyConfig* UTemperatureReceiverSimulationComponent::GetCurrentlyActiveTemperatureEfficiencyConfig() const {
    return NULL;
}

FFixed UTemperatureReceiverSimulationComponent::GetCurrentEfficiency() const {
    return FFixed{};
}


