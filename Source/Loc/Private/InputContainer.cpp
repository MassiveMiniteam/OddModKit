#include "InputContainer.h"
#include "Templates/SubclassOf.h"

UInputContainer::UInputContainer() {
    this->bIsActive = false;
}

void UInputContainer::TickContainer(float DeltaTime) {
}

void UInputContainer::StopContainer(bool bForce) {
}

void UInputContainer::StartContainer() {
}

void UInputContainer::PushInputContextBelow(UInputContext* Context, UInputContext* BelowContext) {
}

void UInputContainer::PushInputContext(UInputContext* Context) {
}

void UInputContainer::PopInputContext(UInputContext* Context) {
}

void UInputContainer::OnInputAxis(UInputActionData* InputAction, ALocPlayerController* PlayerController) {
}

void UInputContainer::OnInputAction(UInputActionData* InputAction, ALocPlayerController* PlayerController) {
}

UInputContext* UInputContainer::GetFirstInputContextOfType(TSubclassOf<UInputContext> Class) const {
    return NULL;
}


