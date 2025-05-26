#include "MaterialAdjustPresentationComponent.h"

UMaterialAdjustPresentationComponent::UMaterialAdjustPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAutomaticallyAddMeshComponents = true;
    this->DefaultExcludingTag = TEXT("ExludeFromMaterialAdjustDefault");
    this->InteractionStateIndicatorMaterial = NULL;
    this->DepthStencilValue = 250;
}

void UMaterialAdjustPresentationComponent::StoreOriginalMaterialsAndMeshComponents() {
}

void UMaterialAdjustPresentationComponent::SetVectorParameterOnAllMaterials(FName ParameterName, FVector Value, bool bIncludeChildActors) {
}

void UMaterialAdjustPresentationComponent::SetScalarParameterOnAllMaterials(FName ParameterName, float Value, bool bIncludeChildActors) {
}

void UMaterialAdjustPresentationComponent::RemoveMaterial(UMaterialInterface* Material) {
}

void UMaterialAdjustPresentationComponent::EnableInteractionStateVisualization(bool bInteractionState) {
}

void UMaterialAdjustPresentationComponent::AddMaterial(UMaterialInterface* Material) {
}


