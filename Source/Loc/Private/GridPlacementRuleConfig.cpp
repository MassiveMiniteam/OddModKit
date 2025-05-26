#include "GridPlacementRuleConfig.h"

UGridPlacementRuleConfig::UGridPlacementRuleConfig() {
    this->bShowRuleWhilePlacing = false;
}

void UGridPlacementRuleConfig::ValidateTilesWithPreviousPlacedGridObject_Implementation(FPlacementRuleParameter& PlacementRuleParameter, FPlacementRuleResult& Result) {
}

bool UGridPlacementRuleConfig::ShouldSnap(const UObject* WorldContext, FIntPoint GridPosition, int32 Rotation, FIntVector& SnapPosition) {
    return false;
}

bool UGridPlacementRuleConfig::ShouldRotate(const UObject* WorldContext, FIntPoint GridPosition, int32 Rotation, int32& SnapRotation) {
    return false;
}

void UGridPlacementRuleConfig::GetValidTilesFromArea_Implementation(FPlacementRuleParameter& PlacementRuleParameter, AGrid* GridInstance, FPlacementRuleResult& Result) {
}

bool UGridPlacementRuleConfig::CheckForSnap_Implementation(FIntPoint GridPosition, int32 Rotation, AGrid* GridInstance, FIntVector& SnapPosition) {
    return false;
}

bool UGridPlacementRuleConfig::CheckForRotation_Implementation(FIntPoint GridPosition, int32 Rotation, AGrid* GridInstance, int32& SnapRotation) {
    return false;
}

bool UGridPlacementRuleConfig::CanBePlaced(const UObject* WorldContext, FPlacementRuleParameter& PlacementRuleParameter, FPlacementRuleResult& Result) {
    return false;
}


