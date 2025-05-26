#include "GE_MovementIsBlocked_IfPathAddonInFrontDemandsIt.h"

UGE_MovementIsBlocked_IfPathAddonInFrontDemandsIt::UGE_MovementIsBlocked_IfPathAddonInFrontDemandsIt() {
    this->SubGridMovement = NULL;
    this->GridNetworkAgentComp = NULL;
    this->bIsCurrentlyWaitingInFrontOfPathAddon = false;
}

bool UGE_MovementIsBlocked_IfPathAddonInFrontDemandsIt::IsInFrontOfPathAddonThatDemandsWaiting() const {
    return false;
}


