#include "GridTileLandscapeLayer.h"

UGridTileLandscapeLayer::UGridTileLandscapeLayer() {
    this->bOverrideMapColor = false;
    this->bSpawnTileMesh = false;
    this->bIsDiggableWall = false;
    this->bIsDiggable = false;
    this->DiggableHealthCurve = NULL;
    this->bSpawnForNeighboursToo = false;
    this->AdditionalPathFindingGridHeight = 0;
}


