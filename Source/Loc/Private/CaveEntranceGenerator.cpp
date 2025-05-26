#include "CaveEntranceGenerator.h"

UCaveEntranceGenerator::UCaveEntranceGenerator() {
    this->bGenerated = false;
    this->bSortValidPosByEdgeLength = false;
    this->BiomeCheckDistance = 3;
    this->CaveEntranceSimulationActor = NULL;
    this->CaveEntranceGridClass = NULL;
    this->bFlattenArea = true;
    this->bOnlyFlattenRange = false;
    this->RadiusToFlatten = 450;
}


