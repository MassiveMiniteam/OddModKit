#include "PlayerIdentificationSimulationComponent.h"

UPlayerIdentificationSimulationComponent::UPlayerIdentificationSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Name = FText::FromString(TEXT("Empty Player Name"));
}

void UPlayerIdentificationSimulationComponent::SetName(FText NewName) {
}

void UPlayerIdentificationSimulationComponent::SetColor(FLinearColor NewColor) {
}


