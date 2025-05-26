#include "ConstructionSiteObjectSimulationComponent.h"

UConstructionSiteObjectSimulationComponent::UConstructionSiteObjectSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->UnderConstructionUnlockable = NULL;
    this->ConstructionFinishedUnlockable = NULL;
    this->bShouldBeTargetedByMinions = true;
}

void UConstructionSiteObjectSimulationComponent::StartConstructionSiteAssembly() {
}

void UConstructionSiteObjectSimulationComponent::OnUnlock(UUnlockableDataAsset* UnlockableDataAsset) {
}

EConstructionSiteState UConstructionSiteObjectSimulationComponent::GetConstructionState() {
    return EConstructionSiteState::Reserved;
}

void UConstructionSiteObjectSimulationComponent::CompleteConstructionSiteAssembly() {
}


