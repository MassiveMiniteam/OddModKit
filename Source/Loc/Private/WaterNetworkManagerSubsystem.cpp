#include "WaterNetworkManagerSubsystem.h"
#include "WaterNetwork.h"
#include "WaterNetworkSimulationComponent.h"

UWaterNetworkManagerSubsystem::UWaterNetworkManagerSubsystem() {
    this->GridNetworkComponentClass = UWaterNetworkSimulationComponent::StaticClass();
    this->NetworkType = AWaterNetwork::StaticClass();
}


