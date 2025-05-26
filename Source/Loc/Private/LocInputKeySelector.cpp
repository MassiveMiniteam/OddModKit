#include "LocInputKeySelector.h"

ULocInputKeySelector::ULocInputKeySelector() {
    this->KeySelectionText = FText::FromString(TEXT("..."));
    this->NoKeySpecifiedText = FText::FromString(TEXT("Empty"));
    this->bAllowModifierKeys = true;
    this->bAllowGamepadKeys = false;
    this->EscapeKeys.AddDefaulted(1);
}

void ULocInputKeySelector::SetTextBlockVisibility(const ESlateVisibility InVisibility) {
}

void ULocInputKeySelector::SetSelectedKey(const FInputChord& InSelectedKey) {
}

void ULocInputKeySelector::SetNoKeySpecifiedText(FText InNoKeySpecifiedText) {
}

void ULocInputKeySelector::SetKeySelectionText(FText InKeySelectionText) {
}

void ULocInputKeySelector::SetIsSelectingKey(bool bInIsSelectingKey) {
}

void ULocInputKeySelector::SetEscapeKeys(const TArray<FKey>& InKeys) {
}

void ULocInputKeySelector::SetAllowModifierKeys(bool bInAllowModifierKeys) {
}

void ULocInputKeySelector::SetAllowGamepadKeys(bool bInAllowGamepadKeys) {
}

void ULocInputKeySelector::HandleIsSelectingKeyChanged() {
}

void ULocInputKeySelector::HandleButtonLostFocus() {
}

bool ULocInputKeySelector::GetIsSelectingKey() const {
    return false;
}


