#include "GlobalStatsTracker.h"
#include "Templates/SubclassOf.h"

UGlobalStatsTracker::UGlobalStatsTracker(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AssignedWorkersCount = 0;
    this->ManuallyCraftedItems = 0;
    this->ReservedPrinterCharges = 0;
    this->Unlockable_TemperatureAffectedAnyWorkstation = NULL;
    this->Unlockable_HostilityAffectedAnyWorkstation = NULL;
}

void UGlobalStatsTracker::ReserveCharge() {
}

void UGlobalStatsTracker::OnTemperatureEfficiencyChangedGlobalEvent(UTemperatureReceiverSimulationComponent* TemperatureReceiverSimulationComponent, FFixed Temperature) {
}

int32 UGlobalStatsTracker::GetReservedCharges() const {
    return 0;
}

UGlobalStatsTracker* UGlobalStatsTracker::GetGlobalStatsTracker(const UObject* WorldContext) {
    return NULL;
}

void UGlobalStatsTracker::FreeCharge() {
}

void UGlobalStatsTracker::AddCalledBackMinion(UMinionControllerSimulationBaseComponent* MinionController, TSubclassOf<AActor> MinionType) {
}


