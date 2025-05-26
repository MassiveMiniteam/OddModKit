#include "RecentlyUnlockedAssetsTrackerSimulationComponent.h"

URecentlyUnlockedAssetsTrackerSimulationComponent::URecentlyUnlockedAssetsTrackerSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void URecentlyUnlockedAssetsTrackerSimulationComponent::RemoveRecentlyUnlockedDataAssets(TArray<UDataAsset*> DataAssets) {
}

TArray<UDataAsset*> URecentlyUnlockedAssetsTrackerSimulationComponent::GetSeenDataAssets() const {
    return TArray<UDataAsset*>();
}

TArray<UDataAsset*> URecentlyUnlockedAssetsTrackerSimulationComponent::GetRecentlyUnlockedAssets() const {
    return TArray<UDataAsset*>();
}

void URecentlyUnlockedAssetsTrackerSimulationComponent::AddSeenDataAssets(TArray<UDataAsset*> DataAssets) {
}

void URecentlyUnlockedAssetsTrackerSimulationComponent::AddRecentlyUnlockedDataAssets(TArray<UDataAsset*> DataAssets) {
}


