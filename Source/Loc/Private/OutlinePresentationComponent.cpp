#include "OutlinePresentationComponent.h"

UOutlinePresentationComponent::UOutlinePresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bOcclusionOutlineBlockMode = false;
    this->bStoreComponentsFromChildActors = false;
}

void UOutlinePresentationComponent::StoreComponentsToOutline() {
}

void UOutlinePresentationComponent::RemoveCustomDepthStencilValue(int32 CustomDepthStencilValue, FName Tag, FName SourceTag) {
}

void UOutlinePresentationComponent::PushCustomDepthStencilValue(int32 CustomDepthStencilValue, int32 Priority, FName Tag, FName SourceTag) {
}

void UOutlinePresentationComponent::ClearAllCustomDepthStencilData() {
}


