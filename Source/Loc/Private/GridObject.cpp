#include "GridObject.h"
#include "PositionSimulationComponent.h"

AGridObject::AGridObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bShouldBeReplaced = false;
    this->bReplacesOtherGridObjectsIfPossible = true;
    this->ConstructableConfig = NULL;
    this->FreeBorderAroundGeneration = 0;
    this->bUpdatePlacementRuleIndicationOnlyOnce = false;
    this->WorldMapID = 1;
    this->PositionSimulationComponent = CreateDefaultSubobject<UPositionSimulationComponent>(TEXT("PositionComponent"));
    this->bIsWalkable = false;
    this->NativeCachedStatsComponent = NULL;
    this->NativeCachedPathAddOnSimulationComponent = NULL;
    this->bFindConstructableConfigOnStart = false;
    this->CurrentWalkabilityBitmask = 0;
    this->DefaultWalkabilityMask = 0;
}

bool AGridObject::ShouldSnapToPlacementRule(const UObject* WorldContext, FIntPoint GridPosition, int32 TargetRotation, FIntVector& SnapPosition) {
    return false;
}

bool AGridObject::ShouldRotateToPlacementRule(const UObject* WorldContext, FIntPoint GridPosition, int32 TargetRotation, int32& SnapRotation) {
    return false;
}

void AGridObject::SetConstructableConfig(UConstructableConfig* InConstructableConfig) {
}

void AGridObject::RelocateGridObject(FIntVector NewCenterLocation, int32 NewRotation) {
}


bool AGridObject::IsWalkable() {
    return false;
}

int32 AGridObject::GetRotation() const {
    return 0;
}

UPositionSimulationComponent* AGridObject::GetPositionSimulationComponent() const {
    return NULL;
}

FIntVector AGridObject::GetPosition() const {
    return FIntVector{};
}

TArray<FIntPoint> AGridObject::GetOccupyingTilesSimulationSafe(const UObject* WorldContext, FIntVector PositionOffset, int32 Rotation) {
    return TArray<FIntPoint>();
}

TArray<FIntPoint> AGridObject::GetOccupyingTilesAdditionalOnly(const UObject* WorldContext, FIntVector position, int32 TargetRotation) {
    return TArray<FIntPoint>();
}

FIntVector AGridObject::GetCornerPosition() const {
    return FIntVector{};
}

FIntPoint AGridObject::GetCenterGridPosition() const {
    return FIntPoint{};
}

UStatsComponent* AGridObject::GetCachedStatsComponent() const {
    return NULL;
}

UPathAddOnSimulationComponent* AGridObject::GetCachedPathAddOnSimulationComponent() const {
    return NULL;
}

TArray<FIntPoint> AGridObject::GetAllOccupyingTiles(const UObject* WorldContext, FIntVector position, int32 TargetRotation) {
    return TArray<FIntPoint>();
}

bool AGridObject::CanBePlaced(const UObject* WorldContext, FIntVector InCenterPosition, int32 TargetRotation, AGridObject* IgnoreGridObject, AGridObject* PreviousBuiltObject) {
    return false;
}

TArray<FIntPoint> AGridObject::CalculateTilesInRangeForEachOccupyingTile(const UObject* WorldContext, int32 Distance) {
    return TArray<FIntPoint>();
}


