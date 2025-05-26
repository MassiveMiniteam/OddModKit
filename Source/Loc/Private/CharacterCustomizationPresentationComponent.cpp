#include "CharacterCustomizationPresentationComponent.h"

UCharacterCustomizationPresentationComponent::UCharacterCustomizationPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CharacterCustomizationSimulationComponent = NULL;
}

void UCharacterCustomizationPresentationComponent::OnCharacterCustomizationChangedEvent_Implementation(UCharacterCustomizationSimulationComponent* Component, FCharacterCustomizationSettings NewCharacterCustomizationSettings) {
}


