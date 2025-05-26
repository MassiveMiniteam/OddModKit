#include "USaveGameUnlockableDataAsset.h"

UUSaveGameUnlockableDataAsset::UUSaveGameUnlockableDataAsset() {
    this->bIsUnlockedByDefault = false;
}

void UUSaveGameUnlockableDataAsset::Unlock(UObject* WorldContext) {
}

bool UUSaveGameUnlockableDataAsset::IsUnlocked(UObject* WorldContext) {
    return false;
}


