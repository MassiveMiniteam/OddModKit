#include "InputContextPasteTool.h"
#include "Templates/SubclassOf.h"

UInputContextPasteTool::UInputContextPasteTool() {
    this->CursorInputContext = NULL;
    this->CurrentRotation = 0;
    this->InvalidTilePreviewPool = NULL;
    this->PastePropertiesMarkerPool = NULL;
    this->InputAction_Confirm = NULL;
    this->InputAction_Rotate = NULL;
    this->InputAction_Cancel = NULL;
    this->CursorType = NULL;
    this->GridIndicatorClass = NULL;
    this->GamepadMovementInputContextClass = NULL;
    this->TileIndicatorClass = NULL;
    this->InvalidTilePreviewActorClass = NULL;
    this->PastePropertiesMarkerClass = NULL;
}

URecipeConfig* UInputContextPasteTool::TryGetRecipeFromCopyData(const FGridObjectCopyData& CopyData) {
    return NULL;
}



void UInputContextPasteTool::OnRotate(UInputActionData* InputAction, ALocPlayerController* Player) {
}


void UInputContextPasteTool::OnCursorGridPositionChanged(UInputContextConstructionToolsCursor* InputContext, FIntPoint GridPosition) {
}

void UInputContextPasteTool::OnConfirm(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextPasteTool::OnCancel(UInputActionData* InputAction, ALocPlayerController* Player) {
}

TArray<FArrayOfIntPointToConstructionConfigs> UInputContextPasteTool::GetValidTilePositionsToTargetInCoherentSegments(TArray<FIntPointToConstructableConfig> TilesToTarget, TSubclassOf<UGridNetworkSimulationComponent> GridNetworkType) const {
    return TArray<FArrayOfIntPointToConstructionConfigs>();
}

AGridObject* UInputContextPasteTool::FindGridObjectToCopyPropertiesFrom(FGridObjectCopyData GOCopyData, FVector SnappedPosition) {
    return NULL;
}

FIntVector UInputContextPasteTool::CalculateWorldPosition(FIntVector RelativePosition) {
    return FIntVector{};
}

FIntPoint UInputContextPasteTool::CalculateWorldGridPosition(FIntPoint RelativeGridPosition) const {
    return FIntPoint{};
}

TArray<FItemStack> UInputContextPasteTool::CalculateOptionalCosts() {
    return TArray<FItemStack>();
}

TMap<UConstructableConfig*, int32> UInputContextPasteTool::CalculateCountPerDragPlaceable() {
    return TMap<UConstructableConfig*, int32>();
}

TMap<UConstructableConfig*, int32> UInputContextPasteTool::CalculateCountPerConstructable() {
    return TMap<UConstructableConfig*, int32>();
}

TArray<FItemStack> UInputContextPasteTool::CalculateCosts() {
    return TArray<FItemStack>();
}


