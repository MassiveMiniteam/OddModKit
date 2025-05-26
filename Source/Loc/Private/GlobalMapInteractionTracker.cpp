#include "GlobalMapInteractionTracker.h"
#include "Templates/SubclassOf.h"

UGlobalMapInteractionTracker::UGlobalMapInteractionTracker(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

UGlobalMapInteractionTracker* UGlobalMapInteractionTracker::GetGlobalMapInteractionTracker(const UObject* WorldContext) {
    return NULL;
}

int32 UGlobalMapInteractionTracker::GetAmountForType(TSubclassOf<ASimulationActor> ActorClass) {
    return 0;
}

void UGlobalMapInteractionTracker::Add(ASimulationActor* InSimulationActor) {
}


