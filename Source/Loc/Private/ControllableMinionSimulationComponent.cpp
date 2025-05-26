#include "ControllableMinionSimulationComponent.h"

UControllableMinionSimulationComponent::UControllableMinionSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CurrentMinionController = NULL;
}

void UControllableMinionSimulationComponent::SetMinionController(UMinionControllerSimulationBaseComponent* NewMinionController) {
}

void UControllableMinionSimulationComponent::RemoveTag(FGameplayTag Tag) {
}

bool UControllableMinionSimulationComponent::IsBusy() const {
    return false;
}

bool UControllableMinionSimulationComponent::CanBeCalled(UMinionControllerSimulationBaseComponent* NewMinionController) {
    return false;
}

void UControllableMinionSimulationComponent::AddTag(FGameplayTag Tag) {
}


