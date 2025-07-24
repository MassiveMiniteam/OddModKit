#include "EntitlementSimulation.h"

UEntitlementSimulation::UEntitlementSimulation(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->EntitlementDataAsset = NULL;
    this->bScheduleDestruction = false;
    this->CurrentDestructionDelayTicks = 0;
}


