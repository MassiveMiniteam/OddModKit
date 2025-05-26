#include "GridTileRule.h"

FGridTileRule::FGridTileRule() {
    this->TopLeft = EGridBiome::None;
    this->TopCenter = EGridBiome::None;
    this->TopRight = EGridBiome::None;
    this->LeftCenter = EGridBiome::None;
    this->CenterCenter = EGridBiome::None;
    this->RightCenter = EGridBiome::None;
    this->BottomLeft = EGridBiome::None;
    this->BottomCenter = EGridBiome::None;
    this->BottomRight = EGridBiome::None;
    this->bCanRotate = false;
}

