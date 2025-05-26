#include "LogicClockSimulationComponent.h"

ULogicClockSimulationComponent::ULogicClockSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanEverTick = true;
}

void ULogicClockSimulationComponent::SetOnTime(FFixed Time) {
}

void ULogicClockSimulationComponent::SetOffTime(FFixed Time) {
}

bool ULogicClockSimulationComponent::IsOn() const {
    return false;
}

FFixed ULogicClockSimulationComponent::GetTotalDuration() const {
    return FFixed{};
}

FFixed ULogicClockSimulationComponent::GetTime01() const {
    return FFixed{};
}

FFixed ULogicClockSimulationComponent::GetOnTime() {
    return FFixed{};
}

FFixed ULogicClockSimulationComponent::GetOffTime() {
    return FFixed{};
}


