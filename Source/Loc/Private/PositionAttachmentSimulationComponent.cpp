#include "PositionAttachmentSimulationComponent.h"

UPositionAttachmentSimulationComponent::UPositionAttachmentSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bClearAttachmentOnLoad = false;
    this->bDestroyOwnerWhenAttachedTargetIsDestroyed = true;
    this->AttachmentSlotIndex = 0;
}

void UPositionAttachmentSimulationComponent::OnAttachedToPositionChanged(UPositionSimulationComponent* AttachedToPositionComponent, FIntVector LastPosition) {
}

void UPositionAttachmentSimulationComponent::OnAttachedActorShutdown(ASimulationActor* AttachedSimulationActor, EDestructionReason Reason) {
}

int32 UPositionAttachmentSimulationComponent::GetAttachmentSlotIndex() const {
    return 0;
}

UPositionSimulationComponent* UPositionAttachmentSimulationComponent::GetAttachedToPositionComponent() const {
    return NULL;
}

void UPositionAttachmentSimulationComponent::AttachTo(UPositionSimulationComponent* NewPositionComponent, int32 Index) {
}


