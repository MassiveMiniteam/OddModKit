#include "PositionSimulationComponent.h"
#include "GridAreaRegistrationStrategy_Radius.h"

UPositionSimulationComponent::UPositionSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->GridAreaRegistrationStrategy = UGridAreaRegistrationStrategy_Radius::StaticClass();
    this->Rotation = 0;
    this->Radius = 25;
    this->PushbackType = EPositionPushbackType::None;
    this->bRegisteredOnPushbackSubSystem = false;
    this->CanBePushedByBitMask = 255;
    this->bCanBePushedBack = true;
    this->UseRadiusOverride = false;
    this->RadiusOverride = 25;
}

void UPositionSimulationComponent::UnregisterOnGrid() {
}

void UPositionSimulationComponent::SetRotation(int32 NewRotation) {
}

void UPositionSimulationComponent::SetRadiusOverride(int32 NewRadiusOverride) {
}

void UPositionSimulationComponent::SetRadius(int32 InRadius) {
}

void UPositionSimulationComponent::SetPositionAndRotation(FIntVector NewPosition, int32 NewRotation) {
}

void UPositionSimulationComponent::SetPosition(FIntVector NewPosition) {
}

void UPositionSimulationComponent::SetEnablePushback(bool bEnable) {
}

void UPositionSimulationComponent::SetCanNotBePushedByMask(const TArray<EPositionPushbackType>& BitmaskEnums) {
}

bool UPositionSimulationComponent::RotateTowardsPosition(const FIntVector& position, const FFixed& Angle) {
    return false;
}

bool UPositionSimulationComponent::RotateTowardsAngle(const FFixed& TargetRotation, const FFixed& Angle) {
    return false;
}

bool UPositionSimulationComponent::RotateTowards(const FIntVector& Direction, const FFixed& Angle) {
    return false;
}

void UPositionSimulationComponent::ResetRadiusOverride() {
}

void UPositionSimulationComponent::RegisterOnGrid(bool bIsLoading) {
}

bool UPositionSimulationComponent::IsOverlapping(UPositionSimulationComponent* Other) {
    return false;
}

bool UPositionSimulationComponent::IsAdvanceBlocked(const FIntVector& MovementDirection, FFixed64 Distance, bool bStopOnOccupiedTiles, int32 StopUpCliffHeight, const FGameplayTagContainer& BlockingTags) {
    return false;
}

FFixed UPositionSimulationComponent::GetSignedRotationDeltaToPosition(const FIntVector& position) const {
    return FFixed{};
}

FFixed UPositionSimulationComponent::GetSignedRotationDeltaTo(const FIntVector& Direction) const {
    return FFixed{};
}

FFixed UPositionSimulationComponent::GetRotationDeltaToPosition(const FIntVector& position) const {
    return FFixed{};
}

FFixed UPositionSimulationComponent::GetRotationDeltaTo(const FIntVector& Direction) const {
    return FFixed{};
}

int32 UPositionSimulationComponent::GetRotation() const {
    return 0;
}

int32 UPositionSimulationComponent::GetRadius() const {
    return 0;
}

FIntVector UPositionSimulationComponent::GetPositionInFront(int32 ForwardDistance) const {
    return FIntVector{};
}

FIntVector UPositionSimulationComponent::GetPosition() const {
    return FIntVector{};
}

FFixed64Vector UPositionSimulationComponent::GetNormalizedDirectionTo(const UPositionSimulationComponent* Other, bool IgnoreCoordinateZ) const {
    return FFixed64Vector{};
}

FIntPoint UPositionSimulationComponent::GetGridPosition() const {
    return FIntPoint{};
}

UGridAreaRegistrationStrategy* UPositionSimulationComponent::GetGridAreaRegistrationStrategyCDO() const {
    return NULL;
}

FFixed64Vector UPositionSimulationComponent::GetForwardNormalized() const {
    return FFixed64Vector{};
}

FIntVector UPositionSimulationComponent::GetForward(int32 Scale) const {
    return FIntVector{};
}

FFixed64 UPositionSimulationComponent::GetDistanceToPositionFFixed(const FIntVector& position, bool IgnoreCoordinateZ) const {
    return FFixed64{};
}

int32 UPositionSimulationComponent::GetDistanceToPosition(const FIntVector& position, bool IgnoreCoordinateZ) const {
    return 0;
}

FFixed64 UPositionSimulationComponent::GetDistanceToGridPositionFFixed(const FIntPoint& Point) const {
    return FFixed64{};
}

int32 UPositionSimulationComponent::GetDistanceTo(const UPositionSimulationComponent* Other, bool IgnoreCoordinateZ) const {
    return 0;
}

int32 UPositionSimulationComponent::GetDistanceSquaredTo(const FIntVector& OtherPosition, bool IgnoreCoordinateZ) const {
    return 0;
}

int32 UPositionSimulationComponent::GetDefaultRadius() const {
    return 0;
}

bool UPositionSimulationComponent::DistanceToPositionIsLessThen(const FIntVector& position, int32 DistanceThreshold) const {
    return false;
}

bool UPositionSimulationComponent::DistanceToPositionComponentIsLessThen(const UPositionSimulationComponent* Other, int32 DistanceThreshold) const {
    return false;
}

FIntVector UPositionSimulationComponent::ConvertLocalPositionToGlobalPosition_WithRotation(FIntVector LocalPosition, int32 RotationIn) const {
    return FIntVector{};
}

FIntVector UPositionSimulationComponent::ConvertLocalPositionToGlobalPosition(FIntVector LocalPosition) const {
    return FIntVector{};
}

FIntVector UPositionSimulationComponent::ConvertLocalDirectionToGlobalDirection(FIntVector LocalDirection) const {
    return FIntVector{};
}

void UPositionSimulationComponent::ChangeRegistrationOnPushbackSubSystem(bool bEnablePushback) {
}

bool UPositionSimulationComponent::CanBePushedBackAndIsRegistered() const {
    return false;
}

bool UPositionSimulationComponent::Advance(const FIntVector& MovementDirection, FFixed Distance, bool bFindClosestWalkablePositionInLineTowardsTarget, bool bStopOnOccupiedTiles, int32 StopUpCliffHeight) {
    return false;
}


