#include "PresetSpawnerConditionComponent.h"

UPresetSpawnerConditionComponent::UPresetSpawnerConditionComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bUnlockOnVillageLoad = false;
    this->bIsSpawned = false;
    this->bIsDespawned = false;
}

void UPresetSpawnerConditionComponent::OnVillageUnloaded(UVillageLoadSimulationSubsystem* InVillageSubsystem) {
}

void UPresetSpawnerConditionComponent::OnVillageLoading(UVillageLoadSimulationSubsystem* InVillageSubsystem) {
}

void UPresetSpawnerConditionComponent::OnVillageLoaded(UVillageLoadSimulationSubsystem* InVillageSubsystem) {
}

void UPresetSpawnerConditionComponent::OnItemUnlock(UUnlockableDataAsset* UnlockableDataAsset) {
}


