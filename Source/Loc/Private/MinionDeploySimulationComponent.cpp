#include "MinionDeploySimulationComponent.h"

UMinionDeploySimulationComponent::UMinionDeploySimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MinionDeployCount = 0;
    this->bEnableMinionDeploy = false;
}

void UMinionDeploySimulationComponent::OnInventoryChanged(int32 Slot) {
}

void UMinionDeploySimulationComponent::GiveBackSpawnedMinion(ASimulationActor* Minion) {
}

void UMinionDeploySimulationComponent::DeployMinionsIfAllowed() {
}


