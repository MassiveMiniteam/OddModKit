#include "WorldGenerationConfig.h"

UWorldGenerationConfig::UWorldGenerationConfig() {
    this->BlockedBiomeConfig = NULL;
    this->VillageBiomeConfig = NULL;
    this->PlaceholderBiomeConfig = NULL;
    this->PlaceholderBiomeCellConfig = NULL;
    this->EmptyBiomeCellConfig = NULL;
    this->EmptyBiomeConfig = NULL;
    this->CellSize = 20;
    this->VillageCellHeight = 1;
    this->BlockedCellHeight = 7;
    this->RandomlyDisturbCellSizes = true;
}


