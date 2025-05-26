#include "BuildPresetsSimulationComponent.h"

UBuildPresetsSimulationComponent::UBuildPresetsSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DefaultNumRows = 5;
    this->BuildPresetUnlockable = NULL;
    this->SelectedRowIndex = 0;
}

void UBuildPresetsSimulationComponent::OnItemUnlocked(UUnlockableDataAsset* UnlockableDataAsset) {
}

bool UBuildPresetsSimulationComponent::IsRowEmpty(int32 Row) const {
    return false;
}

bool UBuildPresetsSimulationComponent::IsRowEditable(int32 Row) {
    return false;
}

bool UBuildPresetsSimulationComponent::HasAssignableInRow(const TScriptInterface<IBuildToolAssignable>& BuildToolAssignable, int32 Row) {
    return false;
}

int32 UBuildPresetsSimulationComponent::GetSelectedRowIndex() const {
    return 0;
}

FBuildPreset UBuildPresetsSimulationComponent::GetSelectedPreset() {
    return FBuildPreset{};
}

int32 UBuildPresetsSimulationComponent::GetPresetsMaxIndex() const {
    return 0;
}

int32 UBuildPresetsSimulationComponent::GetPresetsAmount() const {
    return 0;
}

TArray<FBuildPreset> UBuildPresetsSimulationComponent::GetPresets() const {
    return TArray<FBuildPreset>();
}

bool UBuildPresetsSimulationComponent::CanAddAssignableToRow(const TScriptInterface<IBuildToolAssignable>& BuildToolAssignable, int32 Row) {
    return false;
}


