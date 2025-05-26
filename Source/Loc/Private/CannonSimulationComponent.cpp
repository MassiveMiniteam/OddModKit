#include "CannonSimulationComponent.h"

UCannonSimulationComponent::UCannonSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ShootDistanceInGridTiles = 9;
    this->bBeforeShootingTriggered = false;
    this->InventoryComponent = NULL;
    this->WorkerInventory = NULL;
    this->PositionComponent = NULL;
    this->LogicInputComponent = NULL;
}

void UCannonSimulationComponent::OnGridPositionChanged(UPositionSimulationComponent* InPositionComponent, FIntPoint PreviousGridPosition) {
}

bool UCannonSimulationComponent::IsUseable() const {
    return false;
}

bool UCannonSimulationComponent::CanShootItemConfig(UItemConfig* ItemConfig) {
    return false;
}

void UCannonSimulationComponent::CalculateTargetPosition(AGrid* GridInstance, int32 InRotation, FIntVector Origin, FIntVector& OutTargetPosition, FIntPoint& OutTargetGridPosition) {
}


