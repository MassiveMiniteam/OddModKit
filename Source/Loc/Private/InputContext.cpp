#include "InputContext.h"
#include "Templates/SubclassOf.h"

UInputContext::UInputContext() {
    this->bConsumeAllInputs = false;
    this->bPushButtonPrompts = true;
    this->bStopAnimationOnContextEnd = true;
    this->ButtonPrompts = NULL;
}

void UInputContext::UnBindOnInputAxis(UInputActionData* InputAction) {
}

void UInputContext::UnBindOnInputAction(UInputActionData* InputAction) {
}

void UInputContext::Tick_Implementation(float DeltaTime) {
}

void UInputContext::StopContext(bool bForce) {
}

void UInputContext::StartContext(UInputContainer* Container) {
}

void UInputContext::SchedulePlayAnimationCommand(FGameplayTag Tag, EPlayAnimationCommandOptions Option, bool bChooseRandomAnimation) {
}

void UInputContext::PopThisInputContainer() {
}

void UInputContext::OnStop_Implementation() {
}

void UInputContext::OnStart_Implementation() {
}

void UInputContext::OnLastStopBeforeDestroy_Implementation() {
}

bool UInputContext::OnInputAxis(UInputActionData* InputAction, ALocPlayerController* PlayerController) {
    return false;
}

bool UInputContext::OnInputAction(UInputActionData* InputAction, ALocPlayerController* PlayerController) {
    return false;
}

void UInputContext::OnFirstStart_Implementation() {
}

void UInputContext::IsLocalPlayer(const UObject* WorldContext, APlayerController* PlayerController, EBranchIsLocalPlayerType& OutBranches) {
}

bool UInputContext::HasTag(FGameplayTag Tag) const {
    return false;
}

bool UInputContext::HasAnyTag(const FGameplayTagContainer& TagsToCheck) const {
    return false;
}

UInputContext* UInputContext::GetOrCreateInputContextOfType(TSubclassOf<UInputContext> InputContextType, bool bOnlyFromSameContainer, bool bPushIntoThisContainerIfOriginatesFromAnother) {
    return NULL;
}

bool UInputContext::GetIsLocalPlayer(const UObject* WorldContext, APlayerController* PlayerController) const {
    return false;
}

void UInputContext::BindOnInputAxis(UInputActionData* InputAction, FInputAxisStateChangedEvent Event) {
}

void UInputContext::BindOnInputAction(UInputActionData* InputAction, FInputActionStateChangedEvent Event) {
}


