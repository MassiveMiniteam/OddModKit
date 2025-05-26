#include "UnlockConditionWrapper.h"

UUnlockConditionWrapper::UUnlockConditionWrapper() {
    this->EntitlementDataAsset = NULL;
    this->Achievement = NULL;
    this->Unlockable = NULL;
}

bool UUnlockConditionWrapper::IsUnlocked(UObject* WorldContext, TArray<UDataAsset*>& FailedConditions) {
    return false;
}


