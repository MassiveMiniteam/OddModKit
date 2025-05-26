#include "GiveItemOnReplace.h"

UGiveItemOnReplace::UGiveItemOnReplace(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bDropOnGround = false;
    this->ReplaceComponent = NULL;
}

void UGiveItemOnReplace::OnReplace(UReplaceGridObjectOnConditionComponent* Component, ASimulationPlayer* Player) {
}


