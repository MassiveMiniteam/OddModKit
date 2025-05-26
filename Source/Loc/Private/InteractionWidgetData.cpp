#include "InteractionWidgetData.h"

FInteractionWidgetData::FInteractionWidgetData() {
    this->Type = NULL;
    this->bShowOnHover = false;
    this->bShowOnLookedAt = false;
    this->bWidgetInWorldSpace = false;
    this->Instance = NULL;
    this->SceneComponent = NULL;
}

