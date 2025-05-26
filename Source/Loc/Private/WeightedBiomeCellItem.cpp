#include "WeightedBiomeCellItem.h"

FWeightedBiomeCellItem::FWeightedBiomeCellItem() {
    this->MinDistanceToStart = 0;
    this->MaxDistanceToStart = 0;
    this->MinSpawnAmount = 0;
    this->MaxSpawnAmount = 0;
    this->MinAverageCellHeight = 0;
    this->MaxAverageCellHeight = 0;
    this->Weight = 0;
    this->bUseToFillHoles = false;
    this->GenerationStrategy = NULL;
    this->CellConfig = NULL;
}

