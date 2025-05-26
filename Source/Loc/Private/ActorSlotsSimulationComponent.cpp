#include "ActorSlotsSimulationComponent.h"

UActorSlotsSimulationComponent::UActorSlotsSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->NumSlots = 5;
    this->bBindPositionAttachmentToSlotIndex = false;
}

void UActorSlotsSimulationComponent::RemoveActor(ASimulationActor* Actor) {
}

bool UActorSlotsSimulationComponent::HasActorSlot(ASimulationActor* Actor) const {
    return false;
}

int32 UActorSlotsSimulationComponent::GetFirstEmptySlot() const {
    return 0;
}

int32 UActorSlotsSimulationComponent::GetActorSlotIndex(ASimulationActor* Actor) const {
    return 0;
}

bool UActorSlotsSimulationComponent::CanRemoveActor(ASimulationActor* Actor) const {
    return false;
}

bool UActorSlotsSimulationComponent::CanAddActor(ASimulationActor* Actor, int32 SlotIndex) const {
    return false;
}

void UActorSlotsSimulationComponent::AddActor(ASimulationActor* Actor, int32 SlotIndex) {
}


