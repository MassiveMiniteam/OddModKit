#include "LogicSensorBaseSimulationComponent.h"

ULogicSensorBaseSimulationComponent::ULogicSensorBaseSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Length = 0;
    this->DetectionStrategyIndex = 0;
    this->AngleModifier = 0;
    this->LengthModifier = 0;
    this->PositionComponent = NULL;
}

void ULogicSensorBaseSimulationComponent::OnRelocated(UPositionSimulationComponent* PositionSimulationComponent, FIntVector LastPosition) {
}

void ULogicSensorBaseSimulationComponent::OnGridCellChanged(AGridObject* GridObject, FIntPoint GridPosition) {
}

void ULogicSensorBaseSimulationComponent::InitLogicConnectionComponents() {
}

TArray<FIntPoint> ULogicSensorBaseSimulationComponent::GetStoredRelativeTargetCells() const {
    return TArray<FIntPoint>();
}

TArray<FIntPoint> ULogicSensorBaseSimulationComponent::GetSensorTargetCells() const {
    return TArray<FIntPoint>();
}

TArray<ASimulationActor*> ULogicSensorBaseSimulationComponent::FilterActorsByStrategy(TArray<ASimulationActor*> ActorsToFilter) const {
    return TArray<ASimulationActor*>();
}

TArray<FIntPoint> ULogicSensorBaseSimulationComponent::ConvertCellsToPositionAndRotation(FIntPoint GridPos, int32 Rotation, const TArray<FIntPoint>& CellsToConvert) const {
    return TArray<FIntPoint>();
}

TArray<FIntPoint> ULogicSensorBaseSimulationComponent::CalculateRelativeTargetCells() const {
    return TArray<FIntPoint>();
}


