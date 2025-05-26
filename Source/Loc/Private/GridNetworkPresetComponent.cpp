#include "GridNetworkPresetComponent.h"

UGridNetworkPresetComponent::UGridNetworkPresetComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->GridNetworkType = NULL;
    this->ConstructableConfig = NULL;
    this->GridNetworkManagerClass = NULL;
}


