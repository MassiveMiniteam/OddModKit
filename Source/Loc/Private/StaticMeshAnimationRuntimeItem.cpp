#include "StaticMeshAnimationRuntimeItem.h"

FStaticMeshAnimationRuntimeItem::FStaticMeshAnimationRuntimeItem() {
    this->TargetItemIndex = 0;
    this->CurrentTime = 0.00f;
    this->TimeLastFrame = 0.00f;
    this->Duration = 0.00f;
    this->bStopAnimationWhenFinished = false;
}

