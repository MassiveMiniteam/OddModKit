#include "FactionSimulationComponent.h"

UFactionSimulationComponent::UFactionSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Type = EFactionType::None;
}

bool UFactionSimulationComponent::ConsidersOtherFactionAsPrey(const UFactionSimulationComponent* OtherFaction) const {
    return false;
}

bool UFactionSimulationComponent::CanAttack(const UFactionSimulationComponent* OtherFaction) const {
    return false;
}


