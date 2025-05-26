#include "TickThrottlerPresentationComponent.h"

UTickThrottlerPresentationComponent::UTickThrottlerPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bUseAggregatedTick = true;
    this->ThrottledTickInterval = 1.00f;
    this->NormalTickInterval = 0.00f;
    this->ThrottleCheckInterval = 1.00f;
    this->LocalTime = 0.00f;
}


