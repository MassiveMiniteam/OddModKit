#include "InteractionStrategy.h"

UInteractionStrategy::UInteractionStrategy() {
    this->bDisplayAsHold = false;
    this->bLimitInteractionRangeForMouse = true;
    this->MaxInteractionDistanceForMouse = 1000;
    this->MaxInteractionHeightDistanceForMouse = 200;
    this->AchievementOnExecute = NULL;
}


bool UInteractionStrategy::IsInteractionCurrentlyPossible_Implementation(const UInteractionPresentationComponent* InteractionComponent) const {
    return false;
}


