#include "ForestBiomeGenerator.h"

UForestBiomeGenerator::UForestBiomeGenerator() {
    this->LandscapeGenPriority = 0;
    this->bSpawnInCenterOfCell = false;
    this->ValidSpawnCenterRadius = 5;
    this->MaxGiantTreeAmount = 2;
    this->bApplyWorldSettingsMultiplierToGiantTreeAmount = false;
    this->RadiusFlat = 2;
    this->RadiusToFlatten = 2;
    this->bPropagateThroughCustomLandscapeLayer = true;
    this->bPropagateCliffs = true;
    this->bPropagateNextToCliffs = true;
    this->bRemoveBordersOnCliffs = false;
    this->HeightDifferenceAllowed = 32767;
    this->TreeChance = 20;
    this->FernChance = 5;
    this->GroundLayer = NULL;
    this->ForestTileCount = 50;
}


