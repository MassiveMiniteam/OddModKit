#include "SkyLightPresetStruct.h"

FSkyLightPresetStruct::FSkyLightPresetStruct() {
    this->TurnOnSkyLight = false;
    this->Cubemap = NULL;
    this->SourceCubemapAngle = 0.00f;
    this->CubemapResolution = 0;
    this->SkyDistanceThreshold = 0.00f;
    this->Intensity = 0.00f;
    this->bCaptureEmissiveOnly = false;
    this->bLowerHemisphereIsBlack = false;
}

