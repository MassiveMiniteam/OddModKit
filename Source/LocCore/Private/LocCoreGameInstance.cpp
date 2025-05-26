#include "LocCoreGameInstance.h"

ULocCoreGameInstance::ULocCoreGameInstance() {
    this->AssetDatabase = NULL;
    this->bIsComingFromActivity = false;
    this->bIsLocTestMode = false;
    this->LandscapeObjectTypeQuery = ObjectTypeQuery1;
    this->WorldDynamicTypeQuery = ObjectTypeQuery1;
    this->CurrentSaveGame = NULL;
    this->TicksUntilHide = -1;
}

void ULocCoreGameInstance::ShowLoadingScreen() {
}



void ULocCoreGameInstance::HideLoadingScreen() {
}


