#include "CameraEffectPresentationComponent.h"

UCameraEffectPresentationComponent::UCameraEffectPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RVTResetDistanceInGridUnits = 20;
    this->PostProcessBlendDurationInSeconds = 2.00f;
    this->CachedBiomeCellInstance = NULL;
    this->LastPostProcessActorClass = NULL;
    this->bNeedsSetup = true;
    this->bIsLocalPlayer = false;
    this->LocalPositionCheckDelay = 0.00f;
}

void UCameraEffectPresentationComponent::RestartRVT() {
}


void UCameraEffectPresentationComponent::OnResetRVTPosition_Implementation(FVector NewWorldPosition) {
}

void UCameraEffectPresentationComponent::OnGridPositionChanged(UPositionSimulationComponent* SimulationComponent, FIntPoint LastPosition) {
}

void UCameraEffectPresentationComponent::OnBiomeChanged_Implementation(UBiomeConfig* FromBiome, UBiomeConfig* ToBiome) {
}

ALocPostProcessingVolume* UCameraEffectPresentationComponent::GetActivePostProcessVolume() const {
    return NULL;
}


