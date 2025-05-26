#include "InputContextDragPlacement.h"

UInputContextDragPlacement::UInputContextDragPlacement() {
    this->bIsDragging = false;
    this->bIsInDestructMode = false;
    this->DragPlaceableActorClass = NULL;
    this->bCursorAndIndicatorsShouldBeVisible = true;
    this->CursorInputContext = NULL;
    this->CurrentTileIndicator = NULL;
    this->PreviewPool = NULL;
    this->InvalidTilePreviewPool = NULL;
    this->InvalidTilePreviewActorClass = NULL;
    this->HighlightPresentationComponent = NULL;
    this->CostUI = NULL;
    this->GridNetworkSubsystemClass = NULL;
    this->IndicatorType = NULL;
    this->CursorType = NULL;
    this->CostUIType = NULL;
    this->GridIndicatorType = NULL;
    this->ConstructableConfig = NULL;
    this->IsGridCellsDirty = false;
    this->GamepadMovementInputContextClass = NULL;
    this->GamepadMovementInputContext = NULL;
    this->BuildPlaceInputAction = NULL;
    this->CancelInputAction = NULL;
    this->DestroyInputAction = NULL;
    this->NextObjectInputAction = NULL;
    this->PrevObjectInputAction = NULL;
    this->bNeedsFirstTickSetup = false;
}

void UInputContextDragPlacement::UpdatePreview() {
}

void UInputContextDragPlacement::UpdateHighlightEffect_Implementation() {
}

void UInputContextDragPlacement::TryPlaceObject_Implementation() {
}


void UInputContextDragPlacement::OnPrevObjectIndex(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextDragPlacement::OnNextObjectIndex(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextDragPlacement::OnNewTileHoveredEvent_Implementation() {
}


void UInputContextDragPlacement::OnGridCellChanged(FIntPoint GridPosition) {
}


void UInputContextDragPlacement::OnDestroyInput(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextDragPlacement::OnCancelInput(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextDragPlacement::OnBuildPlaceInput(UInputActionData* InputAction, ALocPlayerController* Player) {
}

TArray<FIntPoint> UInputContextDragPlacement::GetValidTilePositionsToTarget(bool bIgnoreCost) {
    return TArray<FIntPoint>();
}

TArray<FIntPoint> UInputContextDragPlacement::GetTilesInRectangularDragArea() const {
    return TArray<FIntPoint>();
}

TArray<FIntPoint> UInputContextDragPlacement::GetTilePositionsToTarget() const {
    return TArray<FIntPoint>();
}

TArray<FIntPoint> UInputContextDragPlacement::GetInvalidTilePositionsToTarget() {
    return TArray<FIntPoint>();
}


bool UInputContextDragPlacement::CanPlaceObjectAt(FIntPoint position) const {
    return false;
}

bool UInputContextDragPlacement::CanPayForObjectsAmount(int32 ObjectsAmount) const {
    return false;
}


