#include "CaveHandlerPresentationComponent.h"

UCaveHandlerPresentationComponent::UCaveHandlerPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CameraEffectPresentationComponent = NULL;
    this->BiomeMaskMaterialDynamic = NULL;
    this->DynamicBiomeMaskTexture = NULL;
    this->PostProcessComponent = NULL;
}

void UCaveHandlerPresentationComponent::UpdateCaveEnterEvent() {
}

void UCaveHandlerPresentationComponent::SetDynamicMaterial(UMaterialInstanceDynamic* NewMaterial) {
}



void UCaveHandlerPresentationComponent::OnBiomeEffectChanged(UCameraEffectPresentationComponent* InCameraEffectPresentationComponent, UBiomeCellInstance* PreviousCell, UBiomeCellInstance* NewCell) {
}

UTexture2D* UCaveHandlerPresentationComponent::GetDynamicMaskTexture() {
    return NULL;
}


