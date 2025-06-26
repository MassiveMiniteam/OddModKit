#include "MusicSequencePlayerPresentationComponent.h"

UMusicSequencePlayerPresentationComponent::UMusicSequencePlayerPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ClockHandle = NULL;
    this->AudioComponent = NULL;
}


UAudioComponent* UMusicSequencePlayerPresentationComponent::GetAudioComponent() const {
    return NULL;
}


