#include "FoodSeekerComponent.h"

UFoodSeekerComponent::UFoodSeekerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanEverTick = true;
}

bool UFoodSeekerComponent::WantsToEat(const UFoodSourceComponent* FoodSource) const {
    return false;
}

bool UFoodSeekerComponent::IsStuffed() const {
    return false;
}

bool UFoodSeekerComponent::IsHungry() const {
    return false;
}

ASimulationActor* UFoodSeekerComponent::GetClosestDeliciousPerceivedActors() const {
    return NULL;
}

TArray<ASimulationActor*> UFoodSeekerComponent::GetAllDeliciousPerceivedActors() const {
    return TArray<ASimulationActor*>();
}

void UFoodSeekerComponent::EatUntilStuffed(UFoodSourceComponent* FoodSource) {
}

void UFoodSeekerComponent::EatOnce(UFoodSourceComponent* FoodSource) {
}


