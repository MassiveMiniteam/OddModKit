#include "CharacterAudioPresentationComponent.h"

UCharacterAudioPresentationComponent::UCharacterAudioPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AudioDataAsset = NULL;
}

void UCharacterAudioPresentationComponent::PlayAudioByTag(FGameplayTag Tag, ECharacterAudioPlayOption Option) {
}


