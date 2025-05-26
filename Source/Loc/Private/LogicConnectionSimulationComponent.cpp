#include "LogicConnectionSimulationComponent.h"

ULogicConnectionSimulationComponent::ULogicConnectionSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DefaultValue = 0;
    this->OwnerPositionComponent = NULL;
    this->bNeedsRefresh = false;
    this->bWarningAboutConnection = false;
}

void ULogicConnectionSimulationComponent::RegisterOnNetwork() {
}

void ULogicConnectionSimulationComponent::OnOwnerPositionChanged(UPositionSimulationComponent* PositionComponent, FIntVector LastPosition) {
}

void ULogicConnectionSimulationComponent::OnNetworkTilesChanged(TArray<FIntPoint> Tiles) {
}

void ULogicConnectionSimulationComponent::OnNetworkConnectionChange() {
}

void ULogicConnectionSimulationComponent::OnGridNetworkUpdated(AGridNetwork* GridNetwork) {
}

void ULogicConnectionSimulationComponent::OnGridNetworkDestroyed(AGridNetwork* Instance) {
}

bool ULogicConnectionSimulationComponent::IsConnected() const {
    return false;
}

bool ULogicConnectionSimulationComponent::HasConnectionWarning() const {
    return false;
}

bool ULogicConnectionSimulationComponent::HasConnectionIssue() const {
    return false;
}

bool ULogicConnectionSimulationComponent::GetStateAsBool() const {
    return false;
}

int32 ULogicConnectionSimulationComponent::GetRibbonStateAsInt() const {
    return 0;
}

ALogicNetwork* ULogicConnectionSimulationComponent::GetLogicNetwork() const {
    return NULL;
}

FIntPoint ULogicConnectionSimulationComponent::GetGridPosition() const {
    return FIntPoint{};
}

FIntPoint ULogicConnectionSimulationComponent::GetGridOffset() const {
    return FIntPoint{};
}

int32 ULogicConnectionSimulationComponent::GetDefaultValue() const {
    return 0;
}

TArray<int32> ULogicConnectionSimulationComponent::GetActiveBitsOnRibbonChannel() {
    return TArray<int32>();
}

void ULogicConnectionSimulationComponent::CheckConnectionWarning() {
}


