#include "UnitMovementSimulationComponent.h"

UUnitMovementSimulationComponent::UUnitMovementSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanEverTick = true;
    this->CurrentPath = NULL;
    this->CurrentPathTargetIndex = 0;
    this->LastPathTargetIndex = 0;
    this->NewRequestedAcceptanceRadius = 100;
    this->CurrentAcceptanceRadius = 100;
    this->bPositionOrRotationUpdatedLastFrame = false;
    this->RotationLastFrame = 0;
    this->bTeleportIfNoPathFound = false;
}

void UUnitMovementSimulationComponent::StopMovement(EMovementEndResult Reason) {
}

EMovementSetupResult UUnitMovementSimulationComponent::SetTargetByObject(UPositionSimulationComponent* NewTargetPositionComponent, int32 AcceptanceRadius) {
    return EMovementSetupResult::TargetAlreadyReached;
}

EMovementSetupResult UUnitMovementSimulationComponent::SetTargetByCoordinates(const FIntVector& TargetCoordinates, int32 AcceptanceRadius) {
    return EMovementSetupResult::TargetAlreadyReached;
}

void UUnitMovementSimulationComponent::OnNewPathFindingRequestCompleted(UPathFinderComponent* PathFinderComp, EPathFindingRequestResult Result, UPathFindingRequest* Path, FIntVector TargetPosition) {
}

void UUnitMovementSimulationComponent::OnGameplayTagChanged(UStatsComponent* StatsComp, FGameplayTag Tag, FFixed OldValue, FFixed NewValue) {
}

void UUnitMovementSimulationComponent::OnDifficultySettingsChanged(UDifficultySettingsSubsystem* Subsystem) {
}

int32 UUnitMovementSimulationComponent::GetRotationDifferenceToLastFrame() const {
    return 0;
}

FIntVector UUnitMovementSimulationComponent::GetPositionDifferenceToLastFrame() const {
    return FIntVector{};
}

FFixed UUnitMovementSimulationComponent::GetCurrentRotationSpeed() const {
    return FFixed{};
}

FFixed UUnitMovementSimulationComponent::GetCurrentMovementSpeed() const {
    return FFixed{};
}

bool UUnitMovementSimulationComponent::CurrentPathIsValid() const {
    return false;
}


