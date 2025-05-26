#include "AutoScrollBox.h"

UAutoScrollBox::UAutoScrollBox() {
    this->bIsNavigatable = true;
    this->ActiveFocusPath = NULL;
}

void UAutoScrollBox::OnFocusPathChanged(UNavFocusPath* PathIn) {
}


