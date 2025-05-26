#include "ActorPoolManager.h"
#include "Templates/SubclassOf.h"

UActorPoolManager::UActorPoolManager() {
    this->ActorType = NULL;
}

void UActorPoolManager::Setup(TSubclassOf<AActor> InActorType) {
}

AActor* UActorPoolManager::ReceiveFreshActorAt(FIntPoint GridPosition) {
    return NULL;
}

AActor* UActorPoolManager::ReceiveFreshActor() {
    return NULL;
}

void UActorPoolManager::MoveToPool(AActor* Actor) {
}

void UActorPoolManager::MoveAllUsedActorsBackToPool() {
}

void UActorPoolManager::MoveActorAtGridPositionToPool(FIntPoint GridPosition) {
}

bool UActorPoolManager::HasUsedActorAtGridPosition(FIntPoint GridPosition) {
    return false;
}

AActor* UActorPoolManager::GetUsedActorAt(FIntPoint GridPosition) {
    return NULL;
}

TArray<FIntPoint> UActorPoolManager::GetAllUsedActorGridPositions() {
    return TArray<FIntPoint>();
}

TArray<AActor*> UActorPoolManager::GetAllActorsInUse() const {
    return TArray<AActor*>();
}

void UActorPoolManager::ClearPool() {
}


