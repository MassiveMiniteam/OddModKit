#include "LocActorComponent.h"

ULocActorComponent::ULocActorComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsEnabled = true;
    this->bIsDisabledDueToPooling = false;
}

void ULocActorComponent::SetIsEnabled(bool bInIsEnabled) {
}

void ULocActorComponent::OnResetFromPooling_Implementation() {
}

void ULocActorComponent::OnEnabledChanged_Implementation() {
}

bool ULocActorComponent::GetIsEnabled() const {
    return false;
}


