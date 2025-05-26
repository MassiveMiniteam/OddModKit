#include "HostilityRadiusSimulationComponent.h"

UHostilityRadiusSimulationComponent::UHostilityRadiusSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->HostilityLevel = 1;
    this->TimedTargetDetector = NULL;
}

void UHostilityRadiusSimulationComponent::SetHostilityLevel(int32 NewHostilityLevel) {
}

int32 UHostilityRadiusSimulationComponent::GetRadius() const {
    return 0;
}

int32 UHostilityRadiusSimulationComponent::GetHostilityLevel() const {
    return 0;
}


