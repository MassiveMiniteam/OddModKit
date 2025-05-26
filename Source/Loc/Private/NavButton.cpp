#include "NavButton.h"

UNavButton::UNavButton() {
    this->bInteractable = true;
    this->bNavigable = true;
    this->bUnhoverRemovesFocus = false;
    this->bSetInteractionKeyAsUsed = true;
    this->OnInteractionSound = NULL;
    this->OnFocusGainedSound = NULL;
    this->OnFocusLostSound = NULL;
    this->InteractionMode = EInputInteractionMode::Selective;
}


