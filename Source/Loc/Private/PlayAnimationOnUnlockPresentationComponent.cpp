#include "PlayAnimationOnUnlockPresentationComponent.h"

UPlayAnimationOnUnlockPresentationComponent::UPlayAnimationOnUnlockPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CachedAnimationComponent = NULL;
}

void UPlayAnimationOnUnlockPresentationComponent::OnUnlock(UUnlockableDataAsset* UnlockableDataAsset) {
}


