#include "CellISMConfig.h"

FCellISMConfig::FCellISMConfig() {
    this->StaticMesh = NULL;
    this->OptionalMaterial = NULL;
    this->bEnableShadow = false;
    this->bRenderCustomDepthPass = false;
    this->CustomDepthStencilValue = 0;
}

