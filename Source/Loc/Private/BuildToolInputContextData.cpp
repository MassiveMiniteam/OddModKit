#include "BuildToolInputContextData.h"

UBuildToolInputContextData::UBuildToolInputContextData() {
    this->InputContextType = NULL;
    this->BuildToolStrategy = NULL;
}

TSoftObjectPtr<UTexture2D> UBuildToolInputContextData::GetBuildToolAssignableIcon() {
    return NULL;
}


