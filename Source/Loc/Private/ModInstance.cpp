#include "ModInstance.h"

UModInstance::UModInstance() {
    this->bIsEnabled = false;
    this->ModBaseInstance = NULL;
    this->Icon = NULL;
}

bool UModInstance::IsCompatibleWithGameVersion(const FString& GameVersion) {
    return false;
}

FString UModInstance::GetSummaryString() {
    return TEXT("");
}


