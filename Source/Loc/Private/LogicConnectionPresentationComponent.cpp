#include "LogicConnectionPresentationComponent.h"

ULogicConnectionPresentationComponent::ULogicConnectionPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LogicMarkerClass = NULL;
    this->LogicWarningClass = NULL;
    this->bHideEditorPreview = false;
    this->bShowConnectionMarkerInPreview = true;
    this->LogicMarker = NULL;
    this->WarningMarker = NULL;
    this->OwnerPositionSimulationComponent = NULL;
    this->bIndicateConnectionsOnEdges = true;
    this->EdgeMarkerPrimitiveDataIndex = 4;
    this->DirectionsToIndicate.AddDefaulted(4);
    this->SignalPrimitiveDataIndex = 4;
}

void ULogicConnectionPresentationComponent::UpdateIndicationOnTile() {
}

void ULogicConnectionPresentationComponent::OnWarningChanged(ULogicConnectionSimulationComponent* Input) {
}

void ULogicConnectionPresentationComponent::OnSignalChanged_Implementation(ULogicConnectionSimulationComponent* Connection) {
}

void ULogicConnectionPresentationComponent::OnLogicNetworkChanged() {
}

void ULogicConnectionPresentationComponent::OnLogicLayerVisiblityChanged(UEventDataAssetWithState* EventDataAssetWithState, bool bState) {
}

void ULogicConnectionPresentationComponent::OnLeaveLogicMode_Implementation() {
}

void ULogicConnectionPresentationComponent::OnGridObjectPositionChanged(UPositionSimulationComponent* PositionComponent, FIntVector LastPosition) {
}

void ULogicConnectionPresentationComponent::OnEnterLogicMode_Implementation() {
}

void ULogicConnectionPresentationComponent::OnConnectionChanged_Implementation(ULogicConnectionSimulationComponent* Connection) {
}

FVector ULogicConnectionPresentationComponent::GetTargetPosition() const {
    return FVector{};
}

ULogicConnectionSimulationComponent* ULogicConnectionPresentationComponent::GetSimulationComponent() {
    return NULL;
}

ALogicConnectionMarker* ULogicConnectionPresentationComponent::GetConnectionMarker() const {
    return NULL;
}

TArray<int32> ULogicConnectionPresentationComponent::GetActiveBitsOnRibbonChannel() {
    return TArray<int32>();
}


