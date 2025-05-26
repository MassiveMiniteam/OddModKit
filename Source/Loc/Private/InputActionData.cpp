#include "InputActionData.h"

UInputActionData::UInputActionData() {
    this->bOnlyWhenUIClosed = false;
    this->bDevelopmentOnly = false;
    this->bIsNotInDemo = false;
    this->ShowForDevices = EMenuShowForDevice::GamepadAndKeyboard;
    this->bHideInSettings = false;
    this->MinPressDuration = 0.00f;
    this->bWasClicked = false;
    this->bWasPressed = false;
    this->bIsPressed = false;
    this->bWasReleased = false;
    this->AxisValue = 0.00f;
    this->CurrentPressDuration = 0.00f;
    this->bIsUsed = false;
    this->bPressedWasConsumed = false;
    this->LastUsedFrameCount = 0;
    this->bIsUsedByRadialMenu = false;
}

void UInputActionData::SetUsedPressedForClick() {
}

void UInputActionData::SetUsedByRadialMenuAll(const UObject* WorldContext, bool bState) {
}

void UInputActionData::SetUsedByRadialMenu(bool bState) {
}

void UInputActionData::SetUsedAllWithEqualKey(const UObject* WorldContext, const UObject* ConsumerContext, bool bWithoutMod) {
}

void UInputActionData::SetUsed(const UObject* ConsumerContext) {
}

void UInputActionData::SetUnUsed() {
}

void UInputActionData::RemoveKeyReMappingByDevice(bool GamepadKey) {
}

void UInputActionData::RemoveKeyFromKeyReMapping(FInputActionKeyMapping Key) {
}

bool UInputActionData::KeyFoundInKeyReMapping(FInputActionKeyMapping Key) {
    return false;
}

bool UInputActionData::IsVisibleFor(EInputDeviceType Device) const {
    return false;
}

bool UInputActionData::IsDefaultKeyMapping(FInputActionKeyMapping Key) {
    return false;
}

bool UInputActionData::InputActionsHaveCommonKeyMappingInCurrentUsed(UInputActionData* Other, bool bIsGamepad) {
    return false;
}

TArray<FInputActionKeyMapping> UInputActionData::GetKeysPerDeviceAndMapping(TArray<FInputActionKeyMapping> FilterKeyMapping, bool GamepadKey) {
    return TArray<FInputActionKeyMapping>();
}

bool UInputActionData::GetIsUsed() {
    return false;
}

FInputActionKeyMapping UInputActionData::GetDefaultKeyByDevice(EInputDeviceType Device) {
    return FInputActionKeyMapping{};
}

TArray<FInputActionKeyMapping> UInputActionData::GetCurrentUsedKeyMappingByDeviceType(EInputDeviceType Device) {
    return TArray<FInputActionKeyMapping>();
}

TArray<FInputActionKeyMapping> UInputActionData::GetCurrentUsedKeyMapping(bool IsGamepad) {
    return TArray<FInputActionKeyMapping>();
}

bool UInputActionData::ContainsKey(FInputActionKeyMapping Key) {
    return false;
}

void UInputActionData::ClearInput(const UObject* WorldContext) {
}

void UInputActionData::AddKeyToKeyReMapping(FInputActionKeyMapping Key) {
}


