#include "GameplayEffectEmitter.h"

AGameplayEffectEmitter::AGameplayEffectEmitter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bEnableTick = true;
    this->TargetGameplayEffect = NULL;
}

void AGameplayEffectEmitter::SendHitCommand(ASimulationActor* Target) {
}

void AGameplayEffectEmitter::ApplyHit_Implementation(ASimulationActor* Target) {
}


