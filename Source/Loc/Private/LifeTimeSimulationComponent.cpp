#include "LifeTimeSimulationComponent.h"

ULifeTimeSimulationComponent::ULifeTimeSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OnLifeTimeEnds = ELifeTimeEndEvent::MarkAsDeath;
}


