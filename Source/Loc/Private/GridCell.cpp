#include "GridCell.h"

FGridCell::FGridCell() {
    this->Height = 0;
    this->SnowHeight = 0;
    this->GroundLayer = NULL;
    this->LandscapeLayer = NULL;
    this->BiomeCell = NULL;
    this->bHasCustomGroundLayer = false;
    this->bHasCustomLandscapeLayer = false;
    this->bHasCustomHeight = false;
    this->ConnectedEdges = 0;
    this->ObjectEdgeConnectionModifier = 0;
}

