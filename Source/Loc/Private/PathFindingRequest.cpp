#include "PathFindingRequest.h"

UPathFindingRequest::UPathFindingRequest() {
    this->Result = EPathFindingRequestResult::Success;
    this->MirrorRequest = NULL;
    this->bIsReverse = false;
}


