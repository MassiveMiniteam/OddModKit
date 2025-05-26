#include "ConstructableConfig.h"

UConstructableConfig::UConstructableConfig() {
    this->bCanBeRelocated = true;
    this->bCanBeDeconstructed = true;
    this->bCanBeCopied = true;
    this->Category = EBuildCategory::Harvesters;
    this->CategoryUIOrder = 0;
    this->EditPriority = 100;
    this->bOverrideBuildInitialRotation = false;
    this->OverrideBuildInitialRotation = 0;
    this->bHiddenInBuildMenu = false;
    this->GlossaryGameplayUnlock = NULL;
    this->CopyToolPasteOrder = ECopyToolPasteOrder::Late;
}

bool UConstructableConfig::IsAssigningToPresetBarPossible(UObject* WorldContext) {
    return false;
}

TArray<FItemStack> UConstructableConfig::GetPrice(const UObject* WorldContext) const {
    return TArray<FItemStack>();
}

TSoftObjectPtr<UTexture2D> UConstructableConfig::GetBuildToolAssignableIcon() {
    return NULL;
}


