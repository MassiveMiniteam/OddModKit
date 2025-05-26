#include "GE_MovementIsBlocked_IfHeadingIntoAnotherNetworkAgent.h"

UGE_MovementIsBlocked_IfHeadingIntoAnotherNetworkAgent::UGE_MovementIsBlocked_IfHeadingIntoAnotherNetworkAgent() {
    this->SubGridMovement = NULL;
    this->GridNetworkAgentComp = NULL;
    this->bIsCurrentlyHeadingIntoAnotherNetworkAgent = false;
}

bool UGE_MovementIsBlocked_IfHeadingIntoAnotherNetworkAgent::IsHeadingIntoAnotherNetworkAgent() const {
    return false;
}


