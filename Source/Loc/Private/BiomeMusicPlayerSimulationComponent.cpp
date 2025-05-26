#include "BiomeMusicPlayerSimulationComponent.h"

UBiomeMusicPlayerSimulationComponent::UBiomeMusicPlayerSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LastBiomeMusicConfig = NULL;
    this->BiomeTracker = NULL;
}

void UBiomeMusicPlayerSimulationComponent::PlayTrack(TSoftObjectPtr<UMetaSoundSource> Metasound) {
}

void UBiomeMusicPlayerSimulationComponent::PlayNextTrackImmediately() {
}

void UBiomeMusicPlayerSimulationComponent::OnNewMusicSelected_Implementation(const TSoftObjectPtr<UMetaSoundSource>& Metasound, ASimulationPlayer* Player) {
}

void UBiomeMusicPlayerSimulationComponent::OnEnteredNewCellInstance_Implementation(UBiomeTrackerSimulationComponent* Component, UBiomeCellInstance* BiomeCellInstance) {
}




TArray<TSoftObjectPtr<UMetaSoundSource>> UBiomeMusicPlayerSimulationComponent::GetPlayedMusicClips() const {
    return TArray<TSoftObjectPtr<UMetaSoundSource>>();
}


