#include "LogicBridgeSimulationComponent.h"

ULogicBridgeSimulationComponent::ULogicBridgeSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PositionComponent = NULL;
}

void ULogicBridgeSimulationComponent::Unbridge() {
}

void ULogicBridgeSimulationComponent::OnPositionChanged(UPositionSimulationComponent* InPositionComponent, FIntVector LastPosition) {
}

void ULogicBridgeSimulationComponent::OnNetworkTilesChanged(TArray<FIntPoint> Points) {
}

void ULogicBridgeSimulationComponent::OnConnectionChanged(ULogicConnectionSimulationComponent* Connection) {
}

bool ULogicBridgeSimulationComponent::Bridge() {
    return false;
}


