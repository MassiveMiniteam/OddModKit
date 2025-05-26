#include "HostilitySubsystem.h"

UHostilitySubsystem::UHostilitySubsystem() {
    this->CachedEvolutionBudgetToVisualIndexTable = NULL;
}

void UHostilitySubsystem::UnregisterCorruptionMarker(ASimulationActor* Marker) {
}

void UHostilitySubsystem::RegisterCorruptionMarker(ASimulationActor* Marker) {
}

bool UHostilitySubsystem::IsCorruptionMarkerClose(FIntVector PositionToCheck) {
    return false;
}

int32 UHostilitySubsystem::GetVisualHostilityIndexAtPosition(FIntPoint GridPosition) const {
    return 0;
}

TMap<FIntPoint, int32> UHostilitySubsystem::GetCachedHostilityMap() const {
    return TMap<FIntPoint, int32>();
}

int32 UHostilitySubsystem::GetCachedAvailableBudgetAtPosition(FIntPoint GridPosition) const {
    return 0;
}


