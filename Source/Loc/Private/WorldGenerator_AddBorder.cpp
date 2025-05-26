#include "WorldGenerator_AddBorder.h"

UWorldGenerator_AddBorder::UWorldGenerator_AddBorder() {
    this->BlockedBiomeConfig = NULL;
    this->BlockedCellsBottom = 1;
    this->BlockedCellsLeft = 1;
    this->BlockedCellsRight = 1;
    this->BlockedCellsTop = 1;
    this->Condition = NULL;
}


