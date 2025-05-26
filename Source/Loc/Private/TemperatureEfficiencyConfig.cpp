#include "TemperatureEfficiencyConfig.h"

UTemperatureEfficiencyConfig::UTemperatureEfficiencyConfig() {
    this->TemperatureStepsRequiredPerEfficiencyDecreaseStep = 1;
}

FFixed UTemperatureEfficiencyConfig::CalcEfficiency(int32 Temperature) const {
    return FFixed{};
}


