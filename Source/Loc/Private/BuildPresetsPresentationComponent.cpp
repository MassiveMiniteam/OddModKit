#include "BuildPresetsPresentationComponent.h"

UBuildPresetsPresentationComponent::UBuildPresetsPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SelectedRowIndex = 0;
    this->BuildPresetsSimulationComponent = NULL;
}

void UBuildPresetsPresentationComponent::OnBuildPresetsSimulationUpdated(UBuildPresetsSimulationComponent* Component, int32 Index, FBuildPreset Preset, bool bUpdatePresentation) {
}

bool UBuildPresetsPresentationComponent::HasAssignableInRow(const TScriptInterface<IBuildToolAssignable>& BuildToolAssignable, int32 Row) {
    return false;
}

FBuildPreset UBuildPresetsPresentationComponent::GetSelectedPreset() {
    return FBuildPreset{};
}

int32 UBuildPresetsPresentationComponent::GetCurrentRowIndex() const {
    return 0;
}

TArray<FBuildPreset> UBuildPresetsPresentationComponent::GetBuildPresets() {
    return TArray<FBuildPreset>();
}


