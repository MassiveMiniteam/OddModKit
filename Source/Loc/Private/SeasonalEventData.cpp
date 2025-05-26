#include "SeasonalEventData.h"

USeasonalEventData::USeasonalEventData() {
    this->bAlwaysApply = false;
    this->SeasonalEventMaterialIndex = 0;
    this->SeasonalLightPresets = NULL;
}

bool USeasonalEventData::IsActive() {
    return false;
}


