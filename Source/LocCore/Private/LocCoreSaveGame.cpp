#include "LocCoreSaveGame.h"

ULocCoreSaveGame::ULocCoreSaveGame() {
    this->OverrideSeed = 0;
}



void ULocCoreSaveGame::LoadSaveGame(const UObject* WorldContext, bool bIsForNetworking) {
}

bool ULocCoreSaveGame::GetIsEmpty() const {
    return false;
}

void ULocCoreSaveGame::CollectSaveGame(const UObject* WorldContext, bool bIsForNetworking) {
}


