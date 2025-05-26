#include "SimulationActorPreset.h"

USimulationActorPreset::USimulationActorPreset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SimulationActorClass = NULL;
}

FIntVector USimulationActorPreset::GetPositionAsIntVector() {
    return FIntVector{};
}


