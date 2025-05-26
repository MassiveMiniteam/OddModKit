#include "SpawnBlockerSimulationSubsystem.h"

USpawnBlockerSimulationSubsystem::USpawnBlockerSimulationSubsystem() {
}

void USpawnBlockerSimulationSubsystem::RemoveSpawnBlocker(USpawnBlockerComponent* Blocker) {
}

bool USpawnBlockerSimulationSubsystem::IsSpawnBlockerInRange(const FIntVector& WorldPosition) {
    return false;
}

bool USpawnBlockerSimulationSubsystem::IsSpawnBlocked(const FIntVector& WorldPosition, TSoftClassPtr<ASimulationActor> ActorClass) {
    return false;
}

void USpawnBlockerSimulationSubsystem::AddSpawnBlocker(USpawnBlockerComponent* Blocker) {
}


