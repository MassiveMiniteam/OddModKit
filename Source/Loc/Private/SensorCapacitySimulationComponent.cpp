#include "SensorCapacitySimulationComponent.h"

USensorCapacitySimulationComponent::USensorCapacitySimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TargetValue = 50;
    this->CompareRule = ECapacitySensorCompareRule::Above;
    this->Mode = ECapacitySensorMode::Absolute;
}

void USensorCapacitySimulationComponent::SetTargetValue(int32 Value) {
}

void USensorCapacitySimulationComponent::SetTargetInventory(UInventoryComponent* Inventory) {
}

void USensorCapacitySimulationComponent::SetMode(ECapacitySensorMode ModeIn) {
}

void USensorCapacitySimulationComponent::SetCompareRule(ECapacitySensorCompareRule ModeIn) {
}

void USensorCapacitySimulationComponent::OnTargetInventoryChanged(UInventoryComponent* Inventory, bool bAdded, UItemConfig* Item) {
}

void USensorCapacitySimulationComponent::OnDynamicInventoryChanged(UDynamicInventoryRefSimulation* DynamicInventoryRefSimulation, UInventoryComponent* InventoryComponent) {
}

int32 USensorCapacitySimulationComponent::GetTargetValue() const {
    return 0;
}

UInventoryComponent* USensorCapacitySimulationComponent::GetTargetInventory() const {
    return NULL;
}

int32 USensorCapacitySimulationComponent::GetSignalValueOnInvalidInventory() const {
    return 0;
}

ECapacitySensorMode USensorCapacitySimulationComponent::GetMode() const {
    return ECapacitySensorMode::Absolute;
}

ECapacitySensorCompareRule USensorCapacitySimulationComponent::GetCompareRule() const {
    return ECapacitySensorCompareRule::Above;
}


