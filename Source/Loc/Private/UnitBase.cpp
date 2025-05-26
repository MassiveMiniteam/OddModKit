#include "UnitBase.h"

AUnitBase::AUnitBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->NativeCachedPositionSimulationComponent = NULL;
    this->NativeCachedStatsComponent = NULL;
}

UPositionSimulationComponent* AUnitBase::GetPositionSimulationComponent() const {
    return NULL;
}

UStatsComponent* AUnitBase::GetCachedStatsComponent() const {
    return NULL;
}


