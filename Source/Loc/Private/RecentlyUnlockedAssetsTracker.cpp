#include "RecentlyUnlockedAssetsTracker.h"
#include "Templates/SubclassOf.h"

URecentlyUnlockedAssetsTracker::URecentlyUnlockedAssetsTracker(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->UnlockHandler = NULL;
    this->GlobalItemPickupTracker = NULL;
    this->LootDropTracker = NULL;
    this->RecentlyUnlockedAssetTrackerSimulation = NULL;
}

void URecentlyUnlockedAssetsTracker::OnRecentlyUnlockedItemsListChanged_Event(URecentlyUnlockedAssetsTrackerSimulationComponent* Component) {
}

void URecentlyUnlockedAssetsTracker::OnRecentlyUnlockedDataAssetMarkedAsSeen_Event(URecentlyUnlockedAssetsTrackerSimulationComponent* Component, UDataAsset* DataAsset) {
}

void URecentlyUnlockedAssetsTracker::OnRecentlyUnlockedDataAssetAdded_Event(URecentlyUnlockedAssetsTrackerSimulationComponent* Component, UDataAsset* DataAsset) {
}

void URecentlyUnlockedAssetsTracker::OnLootDropped(ULootDropTrackerSimulationComponent* InLootDropTracker, FItemStack DroppedItemStack, ULootDropSimulationComponent* LootDropComponent) {
}

void URecentlyUnlockedAssetsTracker::OnItemUnlocked(UUnlockableDataAsset* UnlockableDataAsset) {
}

void URecentlyUnlockedAssetsTracker::OnItemPickedUp(UGlobalItemPickupTracker* ItemPickupTracker, UItemConfig* RecentlyPickedUpItem, int32 TotalAmount) {
}

void URecentlyUnlockedAssetsTracker::MarkObjectAsSeen(UObject* SeenObject) {
}

bool URecentlyUnlockedAssetsTracker::IsDataAssetRecentlyUnlocked(UObject* Object) {
    return false;
}

bool URecentlyUnlockedAssetsTracker::HasRecentlyUnlockedDataAssetOfType(TArray<TSubclassOf<UDataAsset>> DataAssetTypes) {
    return false;
}

URecentlyUnlockedAssetsTracker* URecentlyUnlockedAssetsTracker::GetRecentlyUnlockedAssetTracker(UObject* WorldContext) {
    return NULL;
}

void URecentlyUnlockedAssetsTracker::AddDataAsset(UDataAsset* InDataAsset) {
}


