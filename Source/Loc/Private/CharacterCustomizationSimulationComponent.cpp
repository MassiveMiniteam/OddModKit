#include "CharacterCustomizationSimulationComponent.h"

UCharacterCustomizationSimulationComponent::UCharacterCustomizationSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bUseDefault = true;
}

void UCharacterCustomizationSimulationComponent::UpdateCharacterSettings(FCharacterCustomizationSettings InCharacterCustomizationSettings) {
}

FCharacterCustomizationSettings UCharacterCustomizationSimulationComponent::GenerateDefaultSettings_Implementation() {
    return FCharacterCustomizationSettings{};
}


