#include "DiggableMeshSimulationComponent.h"

UDiggableMeshSimulationComponent::UDiggableMeshSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LandscapeLayer = NULL;
    this->bShowSnowLayerAfterBreak = true;
    this->GroundMeshMappingAfterBreak = NULL;
}

void UDiggableMeshSimulationComponent::OnGameplayStatChanged(UStatsComponent* InStatsComponent, FGameplayTag Tag, FFixed OldValue, FFixed NewValue) {
}


