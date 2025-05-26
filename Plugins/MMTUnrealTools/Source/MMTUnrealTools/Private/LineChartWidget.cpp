#include "LineChartWidget.h"

ULineChartWidget::ULineChartWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->AxisYAlignment = EAxisYAlignmentMode::Zero;
    this->bFlipYAxis = true;
}

void ULineChartWidget::UpdateVisibilityByTag(FGameplayTag Tag, bool bNewVisibility) {
}

void ULineChartWidget::UpdateVisibilityByAsset(UDataAsset* DataAsset, bool bNewVisibility) {
}

void ULineChartWidget::UpdateLimits(FFloatInterval NewLimitsX, FFloatInterval NewLimitsY, ELimitsMode Mode) {
}

void ULineChartWidget::UpdateChartDataWithTag(FGameplayTag Tag, FLineChartData LineChartData) {
}

void ULineChartWidget::UpdateChartDataByDataAsset(UDataAsset* DataAsset, FLineChartData LineChartData) {
}

void ULineChartWidget::UpdateAllDisplayedData() {
}


TArray<FLineChartData> ULineChartWidget::GetDisplayedLineChartData() const {
    return TArray<FLineChartData>();
}

FVector2D ULineChartWidget::GetAxisYOrigin() const {
    return FVector2D{};
}

void ULineChartWidget::DeleteDataWithTag(FGameplayTag Tag) {
}

void ULineChartWidget::DeleteDataByDataAsset(UDataAsset* DataAsset) {
}

void ULineChartWidget::ClearAllData() {
}

FVector2D ULineChartWidget::CalcPixelPosition_StartAxisY() const {
    return FVector2D{};
}

FVector2D ULineChartWidget::CalcPixelPosition_StartAxisX() const {
    return FVector2D{};
}

FVector2D ULineChartWidget::CalcPixelPosition_EndAxisY() const {
    return FVector2D{};
}

FVector2D ULineChartWidget::CalcPixelPosition_EndAxisX() const {
    return FVector2D{};
}

FVector2D ULineChartWidget::CalcPixelPosition(FVector2D DataPoint) const {
    return FVector2D{};
}


