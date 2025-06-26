#include "ProductionRateBoundTimerComponent.h"

UProductionRateBoundTimerComponent::UProductionRateBoundTimerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StatsComponent = NULL;
}

FFixed UProductionRateBoundTimerComponent::GetProductionRatePerMinute() {
    return FFixed{};
}


