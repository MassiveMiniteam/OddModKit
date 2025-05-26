#include "ModDependencyError.h"

FModDependencyError::FModDependencyError() {
    this->bNeedsEnable = false;
    this->bNeedsDisable = false;
    this->bNeedsInstall = false;
    this->ModInstance = NULL;
}

