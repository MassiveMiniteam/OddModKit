#include "GlobalItemPickupTracker.h"

UGlobalItemPickupTracker::UGlobalItemPickupTracker(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UGlobalItemPickupTracker::OnPickedUpItem(ASimulationPlayer* Player, UInventoryComponent* InventoryComponent, UItemConfig* Item, int32 Amount) {
}

bool UGlobalItemPickupTracker::HasEverPickedUpItemOfType(UItemConfig* ItemConfig) {
    return false;
}

UGlobalItemPickupTracker* UGlobalItemPickupTracker::GetGlobalItemPickupTracker(const UObject* WorldContext) {
    return NULL;
}


