#include "WorldGenerationBiomeEntry.h"

FWorldGenerationBiomeEntry::FWorldGenerationBiomeEntry() {
    this->Biome = NULL;
    this->MinDistanceToStart = 0;
    this->MaxDistanceToStart = 0;
    this->MaxCellCount = 0;
    this->Priority = 0;
    this->bIsBlob = false;
    this->BlobMinAmount = 0;
    this->BlobMaxAmount = 0;
    this->BlobMinAngle = 0;
    this->BlobMaxAngle = 0;
    this->bIsSecondaryCircleBiome = false;
}

