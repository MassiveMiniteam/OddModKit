#include "RecipeConfig.h"

URecipeConfig::URecipeConfig() {
    this->bNeedsFuel = false;
    this->bConsumesItems = true;
    this->TemperatureEfficiencyOverwrite = NULL;
    this->OutputBehaviour = ERecipeOutputBehaviour::All;
}

bool URecipeConfig::NeedsFuel() const {
    return false;
}

int32 URecipeConfig::GetNumberOfProducedItemTypes() const {
    return 0;
}


