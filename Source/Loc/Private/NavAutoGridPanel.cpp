#include "NavAutoGridPanel.h"

UNavAutoGridPanel::UNavAutoGridPanel() {
    this->GridWidth = 5;
    this->MaxWidthCheck = 10;
    this->MaxHeightCheck = 10;
    this->bEnableHorizontalWrapping = false;
    this->bEnableVerticalWrapping = false;
}

void UNavAutoGridPanel::RefreshGridLayout() {
}

UUniformGridSlot* UNavAutoGridPanel::AddChildToAutoGrid(UWidget* Content) {
    return NULL;
}


