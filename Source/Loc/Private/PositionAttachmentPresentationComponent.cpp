#include "PositionAttachmentPresentationComponent.h"

UPositionAttachmentPresentationComponent::UPositionAttachmentPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAttachRotation = false;
}

void UPositionAttachmentPresentationComponent::OnAttachmentChanged(UPositionAttachmentSimulationComponent* AttachmentComponent, UPositionSimulationComponent* AttachedToPositionComponent) {
}

AActor* UPositionAttachmentPresentationComponent::GetAttachedToPresentationActor() const {
    return NULL;
}

void UPositionAttachmentPresentationComponent::AttachToActor_PresentationOnly(AActor* TargetActor, int32 Index) {
}


