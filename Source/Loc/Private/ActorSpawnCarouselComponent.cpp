#include "ActorSpawnCarouselComponent.h"

UActorSpawnCarouselComponent::UActorSpawnCarouselComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->NumMaxActors = 5;
    this->ActorClass = NULL;
}

ASimulationActor* UActorSpawnCarouselComponent::SpawnActor(FIntVector CornerLocation, int32 Rotation, FActorSpawnCarouselCallback BeforeRegistrationCallback) {
    return NULL;
}

void UActorSpawnCarouselComponent::OnSimulationActorShutDown(ASimulationActor* Actor, EDestructionReason Reason) {
}

TArray<ASimulationActor*> UActorSpawnCarouselComponent::GetActors() const {
    return TArray<ASimulationActor*>();
}

void UActorSpawnCarouselComponent::DestroyActor(ASimulationActor* Actor) {
}


