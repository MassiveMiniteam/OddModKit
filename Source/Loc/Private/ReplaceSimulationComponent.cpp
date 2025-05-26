#include "ReplaceSimulationComponent.h"

UReplaceSimulationComponent::UReplaceSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bOnlyIfDoesntExist = false;
    this->bRaycastTerrainForPresentation = true;
    this->ReplacingClass = NULL;
}


