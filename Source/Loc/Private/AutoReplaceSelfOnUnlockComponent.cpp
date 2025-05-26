#include "AutoReplaceSelfOnUnlockComponent.h"

UAutoReplaceSelfOnUnlockComponent::UAutoReplaceSelfOnUnlockComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->UnlockHandler = NULL;
    this->bUseDelay = false;
    this->Timer = NULL;
    this->MyUnlockable = NULL;
}

void UAutoReplaceSelfOnUnlockComponent::TimerUpdated(USimulationTimerComponent* InTimer, FFixed Progess) {
}

void UAutoReplaceSelfOnUnlockComponent::TimerFired(USimulationTimerComponent* InTimer) {
}

void UAutoReplaceSelfOnUnlockComponent::OnUnlock(UUnlockableDataAsset* Unlockable) {
}


