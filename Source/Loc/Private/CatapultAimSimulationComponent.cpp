#include "CatapultAimSimulationComponent.h"
#include "Templates/SubclassOf.h"

UCatapultAimSimulationComponent::UCatapultAimSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bStartTickEnabled = true;
    this->WorkerInventory = NULL;
}

void UCatapultAimSimulationComponent::PickNewTargetActor() {
}

bool UCatapultAimSimulationComponent::IsTargetActorValid() const {
    return false;
}

bool UCatapultAimSimulationComponent::IsTargetActorInShootingAngle() const {
    return false;
}

FFixed UCatapultAimSimulationComponent::GetTargetDistance() const {
    return FFixed{};
}

FFixed UCatapultAimSimulationComponent::GetLocalRotation() const {
    return FFixed{};
}

TSubclassOf<UGameplayAbilityTargeting> UCatapultAimSimulationComponent::GetCurrentTargetingClass() const {
    return NULL;
}

ASimulationActor* UCatapultAimSimulationComponent::GetCurrentTargetActor() const {
    return NULL;
}


