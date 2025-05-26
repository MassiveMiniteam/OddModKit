#include "WorldGenerator_PlaceAndExpandBiome.h"

UWorldGenerator_PlaceAndExpandBiome::UWorldGenerator_PlaceAndExpandBiome() {
    this->LookForValidOriginCellsDistance = 0;
    this->BiomeConfig = NULL;
    this->ExpandFrom = 0;
    this->ExpandBy = 1;
    this->ConditionForAllDistances = NULL;
}


