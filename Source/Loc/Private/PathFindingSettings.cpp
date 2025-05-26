#include "PathFindingSettings.h"

FPathFindingSettings::FPathFindingSettings() {
    this->JumpDownMaxHeight = 0;
    this->JumpUpMaxHeight = 0;
    this->JumpDownCost = 0;
    this->JumpUpCost = 0;
    this->bCanWalkOnCliffTiles = false;
    this->bCanUseGridNavigationJumps = false;
    this->bTreatJumpsAsNormalWalking = false;
    this->bIsBigUnit = false;
    this->bAllowAdditionalGridHeightSettings = false;
    this->CustomWalkabilityMask = 0;
    this->bForcePathfindingComplete = false;
    this->CalculationsPerTick = 0;
}

