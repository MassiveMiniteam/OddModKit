#include "SplinePainterWidget.h"

USplinePainterWidget::USplinePainterWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->ThicknessZoomedIn = 11.00f;
    this->ThicknessZoomedOut = 2.75f;
    this->WorldGenerator = NULL;
}

void USplinePainterWidget::SetZoomMultiplier(float Value) {
}

void USplinePainterWidget::OverwriteSplines(const TArray<FSplinePainterStruct>& NewSplines) {
}

void USplinePainterWidget::ClearSplines() {
}

void USplinePainterWidget::AddSpline(const FSplinePainterStruct& NewPaintedSpline) {
}


