#include "RecipeTrackerDataView.h"

URecipeTrackerDataView::URecipeTrackerDataView() {
    this->NumSnapShots = 360;
    this->ItemConfig = NULL;
    this->ExtremaMinY = 0.00f;
    this->ExtremaMaxY = 0.00f;
    this->ExtremaMinX = 0.00f;
    this->ExtremaMaxX = 0.00f;
    this->Type = ERecipeTrackType::Production;
}

void URecipeTrackerDataView::SetType(ERecipeTrackType TypeIn) {
}

void URecipeTrackerDataView::SetTimeFrameMin(int32 Minutes) {
}

void URecipeTrackerDataView::SetTimeFrame(int32 InNumSnapshots) {
}

void URecipeTrackerDataView::SetItemConfig(UItemConfig* ItemConfigIn) {
}

void URecipeTrackerDataView::Refresh() {
}

void URecipeTrackerDataView::Init(UItemConfig* ItemConfigIn, ERecipeTrackType TypeIn) {
}

ERecipeTrackType URecipeTrackerDataView::GetType() const {
    return ERecipeTrackType::Production;
}

int32 URecipeTrackerDataView::GetNumDataPoints() {
    return 0;
}

UItemConfig* URecipeTrackerDataView::GetItemConfig() const {
    return NULL;
}

TArray<FVector2D> URecipeTrackerDataView::GetGraphPoints() {
    return TArray<FVector2D>();
}

float URecipeTrackerDataView::GetExtremaMinY() const {
    return 0.0f;
}

float URecipeTrackerDataView::GetExtremaMinX() const {
    return 0.0f;
}

float URecipeTrackerDataView::GetExtremaMaxY() const {
    return 0.0f;
}

float URecipeTrackerDataView::GetExtremaMaxX() const {
    return 0.0f;
}


