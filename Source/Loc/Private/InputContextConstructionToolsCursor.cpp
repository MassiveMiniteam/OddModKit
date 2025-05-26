#include "InputContextConstructionToolsCursor.h"
#include "Templates/SubclassOf.h"

UInputContextConstructionToolsCursor::UInputContextConstructionToolsCursor() {
    this->InputContextSubsystem = NULL;
    this->CursorActor = NULL;
    this->ObjectQueryTypes.AddDefaulted(2);
}

AActor* UInputContextConstructionToolsCursor::SpawnCursorActor(TSubclassOf<AActor> CursorClass) {
    return NULL;
}

AActor* UInputContextConstructionToolsCursor::SpawnActorAttachedToGridPosition(TSubclassOf<AActor> GridIndicatorClass) {
    return NULL;
}

void UInputContextConstructionToolsCursor::SetObjectQueryTypes(const TArray<TEnumAsByte<EObjectTypeQuery>>& NewObjectQueryTypes) {
}

void UInputContextConstructionToolsCursor::SetCursorPosition(const FVector& NewCursorPosition) {
}

void UInputContextConstructionToolsCursor::SetCursorHeight(float NewHeight) {
}

void UInputContextConstructionToolsCursor::RaycastCursorLocationToLandscape() {
}

TArray<FIntPoint> UInputContextConstructionToolsCursor::GetTilesInDragArea(FIntPoint StartGridPosition) {
    return TArray<FIntPoint>();
}

FVector UInputContextConstructionToolsCursor::GetMouseHitOrCursorPosition(float CursorSphereRadius) const {
    return FVector{};
}

FVector UInputContextConstructionToolsCursor::GetHoveredGridTileCenterPosition() const {
    return FVector{};
}

TArray<AActor*> UInputContextConstructionToolsCursor::GetGridPositionAttachedActors() const {
    return TArray<AActor*>();
}

FVector UInputContextConstructionToolsCursor::GetCursorPosition() const {
    return FVector{};
}

FIntVector UInputContextConstructionToolsCursor::GetCursorGridPositionCenter() const {
    return FIntVector{};
}

FIntPoint UInputContextConstructionToolsCursor::GetCursorGridPosition() const {
    return FIntPoint{};
}

AActor* UInputContextConstructionToolsCursor::GetCursorActor() const {
    return NULL;
}

TArray<UPrimitiveComponent*> UInputContextConstructionToolsCursor::FindComponentsUnderMouseOrCursorPosition(float SphereOverlapRadius) {
    return TArray<UPrimitiveComponent*>();
}

AActor* UInputContextConstructionToolsCursor::FindActorUnderMouseOrCursorPosition_BySimulationComponent(TSubclassOf<USimulationActorComponent> SimulationComponentClass, float SphereOverlapRadius) {
    return NULL;
}

AActor* UInputContextConstructionToolsCursor::FindActorUnderMouseOrCursorPosition_BySimulationClass(TSubclassOf<ASimulationActor> SimulationActorClass, float SphereOverlapRadius) {
    return NULL;
}

TArray<AActor*> UInputContextConstructionToolsCursor::FindActorsUnderMouseOrCursorPosition(float SphereOverlapRadius) {
    return TArray<AActor*>();
}

TArray<AActor*> UInputContextConstructionToolsCursor::FindActorsFromCameraSphereTraceToCursorPosition(float SphereOverlapRadius) {
    return TArray<AActor*>();
}

AActor* UInputContextConstructionToolsCursor::FindActorAttachedToGridPositionByClass(TSubclassOf<AActor> GridIndicatorClass) const {
    return NULL;
}

void UInputContextConstructionToolsCursor::CalculateMinMaxForDragArea(FIntPoint StartGridPosition, FIntPoint& Out_Min, FIntPoint& Out_Max) {
}


