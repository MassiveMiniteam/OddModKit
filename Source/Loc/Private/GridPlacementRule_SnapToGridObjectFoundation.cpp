#include "GridPlacementRule_SnapToGridObjectFoundation.h"

UGridPlacementRule_SnapToGridObjectFoundation::UGridPlacementRule_SnapToGridObjectFoundation() {
}

bool UGridPlacementRule_SnapToGridObjectFoundation::IsTileAvailableAsAdditionalTile(FPlacementRuleParameter& PlacementRuleParameter, TArray<AGridObject*> GridObjectsOnTile, AActor* FoundActor) {
    return false;
}

bool UGridPlacementRule_SnapToGridObjectFoundation::IsOfMatchingType(AGridObject* GridObject) {
    return false;
}

bool UGridPlacementRule_SnapToGridObjectFoundation::GetIsClassWhitelisted(UClass* Class) {
    return false;
}

bool UGridPlacementRule_SnapToGridObjectFoundation::AreActorsWhitelistedOrIgnored(const TArray<AGridObject*>& GridObjectsOnTile, AActor*& IgnoreActor) {
    return false;
}


