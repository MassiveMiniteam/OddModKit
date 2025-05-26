#include "TrainsConnectionChangeDelegateParams.h"

FTrainsConnectionChangeDelegateParams::FTrainsConnectionChangeDelegateParams() {
    this->FirstPole = NULL;
    this->FirstConnection = NULL;
    this->SecondConnection = NULL;
    this->InputContext = NULL;
    this->bFailDueToIntersection = false;
    this->HoveredPole = NULL;
    this->HoveredRail = NULL;
}

