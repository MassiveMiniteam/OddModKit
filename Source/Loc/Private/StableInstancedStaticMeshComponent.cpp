#include "StableInstancedStaticMeshComponent.h"

UStableInstancedStaticMeshComponent::UStableInstancedStaticMeshComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCreatePhysicsState = true;
    this->bEnablePooling = true;
}


