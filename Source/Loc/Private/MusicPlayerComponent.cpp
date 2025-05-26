#include "MusicPlayerComponent.h"

UMusicPlayerComponent::UMusicPlayerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LastBiomeMusicConfig = NULL;
    this->MinWaitInterval = 120.00f;
    this->MaxWaitInterval = 240.00f;
    this->ElapsedTime = 0.00f;
    this->WaitInterval = 180.00f;
    this->BiomeTracker = NULL;
}

void UMusicPlayerComponent::SetTracksAsUnplayed(TArray<TSoftObjectPtr<UMetaSoundSource>> Tracks) {
}

void UMusicPlayerComponent::SetTracksAsPlayed(TArray<TSoftObjectPtr<UMetaSoundSource>> Tracks) {
}

void UMusicPlayerComponent::ResetAll() {
}

void UMusicPlayerComponent::PlayTrack(TSoftObjectPtr<UMetaSoundSource> Metasound) {
}

void UMusicPlayerComponent::PlayNextTrackImmediately() {
}

void UMusicPlayerComponent::OnNewMusicSelected_Implementation(const TSoftObjectPtr<UMetaSoundSource>& Metasound, ASimulationPlayer* Player) {
}

void UMusicPlayerComponent::OnEnteredNewCellInstance_Implementation(UBiomeTrackerSimulationComponent* Component, UBiomeCellInstance* BiomeCellInstance) {
}




TArray<TSoftObjectPtr<UMetaSoundSource>> UMusicPlayerComponent::GetPlayedMusicClips() const {
    return TArray<TSoftObjectPtr<UMetaSoundSource>>();
}


