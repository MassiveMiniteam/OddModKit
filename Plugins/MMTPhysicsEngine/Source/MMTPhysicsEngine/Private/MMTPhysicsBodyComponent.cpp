#include "MMTPhysicsBodyComponent.h"

UMMTPhysicsBodyComponent::UMMTPhysicsBodyComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

FFixed64Vector UMMTPhysicsBodyComponent::GetLocation() const {
    return FFixed64Vector{};
}

void UMMTPhysicsBodyComponent::DEBUG_AddForceY() {
}

void UMMTPhysicsBodyComponent::DEBUG_AddForceX() {
}

void UMMTPhysicsBodyComponent::AddForce(const FFixed64Vector& Force) {
}


