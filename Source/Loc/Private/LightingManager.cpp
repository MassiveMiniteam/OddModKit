#include "LightingManager.h"

ALightingManager::ALightingManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LerpDuration = 2.00f;
    this->CurrentSkylightComponent = NULL;
    this->CurrentDirectionalLightComponent = NULL;
    this->CurrentPresets = NULL;
}

void ALightingManager::LerpNewLightPresets(UDirectionalLightComponent* DirectionalLightComponent, USkyLightComponent* SkyLightComponent, ULightPresetsData* Presets, float Duration) {
}


