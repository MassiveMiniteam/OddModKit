#include "MinionCallbackInputContext.h"

UMinionCallbackInputContext::UMinionCallbackInputContext() {
    this->MyMinionController = NULL;
    this->CallbackAction = NULL;
    this->CursorReference = NULL;
    this->CallbackAreaReference = NULL;
}

AActor* UMinionCallbackInputContext::TryGetCursor() {
    return NULL;
}

bool UMinionCallbackInputContext::TryCallbackMinion(UControllableMinionSimulationComponent* MinionComponent) {
    return false;
}



void UMinionCallbackInputContext::OnCallbackInput(UInputActionData* InputAction, ALocPlayerController* Player) {
}



