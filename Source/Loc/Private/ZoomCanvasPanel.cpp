#include "ZoomCanvasPanel.h"
#include "Components/SlateWrapperTypes.h"

UZoomCanvasPanel::UZoomCanvasPanel() {
    this->bIsVariable = false;
    this->Visibility = ESlateVisibility::SelfHitTestInvisible;
    this->AvailableZoomLevels.AddDefaulted(6);
    this->ZoomIndex = 2;
}

void UZoomCanvasPanel::ZoomOut() {
}

void UZoomCanvasPanel::ZoomIn() {
}

void UZoomCanvasPanel::SetZoomLevel(int32 InZoomLevelIndex) {
}

FVector2D UZoomCanvasPanel::GetCurrentDimensions() const {
    return FVector2D{};
}

UZoomCanvasPanelSlot* UZoomCanvasPanel::AddChildToZoomCanvas(UWidget* Content, bool bIgnoreResizeOnZoomLevelChange) {
    return NULL;
}


