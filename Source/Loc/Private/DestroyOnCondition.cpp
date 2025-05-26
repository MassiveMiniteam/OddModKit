#include "DestroyOnCondition.h"

UDestroyOnCondition::UDestroyOnCondition(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Condition = NULL;
    this->UnlockHandlingSimulationComponent = NULL;
}

void UDestroyOnCondition::OnUnlock(UUnlockableDataAsset* UnlockableDataAsset) {
}


