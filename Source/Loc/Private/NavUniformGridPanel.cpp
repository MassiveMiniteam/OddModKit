#include "NavUniformGridPanel.h"

UNavUniformGridPanel::UNavUniformGridPanel() {
    this->OnTransitionHorizontalSound = NULL;
    this->OnTransitionVerticalSound = NULL;
    this->bSelectLastColumnAndRow = true;
    this->bSelectNearestSlotOnEnter = true;
}


