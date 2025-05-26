#include "InputContextSubsystem.h"
#include "Templates/SubclassOf.h"

UInputContextSubsystem::UInputContextSubsystem() {
    this->InputActionLibrary = NULL;
    this->bHasFocus = true;
    this->ActiveDeviceMapping = NULL;
    this->CurrentGamepadDevice = EInputDeviceType::GamepadXbox;
    this->DefaultActionMapping = NULL;
    this->bInputEnabled = true;
    this->bLastInputEnabled = true;
}

void UInputContextSubsystem::UpdateInputAxisDataState(const UObject* WorldContext, float AxisValue, UInputActionData* Data) {
}

void UInputContextSubsystem::UpdateInputAxesWithKey(const UObject* WorldContext, float AxisValue, FInputActionKeyMapping Key) {
}

void UInputContextSubsystem::UpdateInputActionsWithKey(const UObject* WorldContext, EBranchInputActioKeyState InKeyState, FInputActionKeyMapping Key) {
}

void UInputContextSubsystem::UpdateInputActionDataState(const UObject* WorldContext, EBranchInputActioKeyState InKeyState, UInputActionData* Data) {
}

void UInputContextSubsystem::UpdateActiveInputDeviceMapping(UInputDeviceMapping* Mapping) {
}

void UInputContextSubsystem::Tick(const UObject* WorldContext, float DeltaTime) {
}

void UInputContextSubsystem::SetUsedByRadialMenuAll(UInputActionData* Data, bool bState, const UObject* ConsumerContext) {
}

void UInputContextSubsystem::SetUsedAllWithEqualKey(UInputActionData* Data, const UObject* ConsumerContext, bool bWithoutMod) {
}

void UInputContextSubsystem::SetCurrentGamepadDevice(EInputDeviceType DeviceType) {
}

void UInputContextSubsystem::RemoveReceiver(TScriptInterface<IInputReceiver> Receiver) {
}

void UInputContextSubsystem::RegisterInputAction(UInputActionData* Data) {
}

UInputContainer* UInputContextSubsystem::PushSingleInputContext(UInputContext* Context) {
    return NULL;
}

void UInputContextSubsystem::PushInputContainerToTop(UInputContainer* Container) {
}

void UInputContextSubsystem::PushInputContainer(UInputContainer* Container) {
}

void UInputContextSubsystem::PopInputContainer(UInputContainer* Container) {
}

void UInputContextSubsystem::PopAllInputContainers(bool bForce) {
}

void UInputContextSubsystem::OnWindowFocusChanged(bool bIsFocused) {
}

void UInputContextSubsystem::OnModsChanged() {
}

void UInputContextSubsystem::OnDetectedInputDeviceChanged(ESwitcherooInputDevice Device) {
}

bool UInputContextSubsystem::IsShiftPressed(const UObject* WorldContext) const {
    return false;
}

bool UInputContextSubsystem::IsCtrlPressed(const UObject* WorldContext) const {
    return false;
}

bool UInputContextSubsystem::IsContextOnTheStack(const UInputContext* Context) const {
    return false;
}

bool UInputContextSubsystem::IsContainerOnTheStack(const UInputContainer* Container) const {
    return false;
}

bool UInputContextSubsystem::IsAxisConsumedByRadialMenu(FInputActionKeyMapping Axis) {
    return false;
}

bool UInputContextSubsystem::IsAltPressed(const UObject* WorldContext) const {
    return false;
}

bool UInputContextSubsystem::HasUIInputContextWithWidgetType(TSubclassOf<UNavUserWidget> WidgetClass, bool bSearchWholeWidgetTree) {
    return false;
}

bool UInputContextSubsystem::HasUIInputContextWithAnyOfTheseWidgets(TArray<TSubclassOf<UNavUserWidget>> WidgetClasses, bool bSearchWholeWidgetTree) {
    return false;
}

bool UInputContextSubsystem::HasMouseKeyboardInput() const {
    return false;
}

bool UInputContextSubsystem::HasControllerInput() const {
    return false;
}

bool UInputContextSubsystem::HasActiveInputDeviceFeatureSupport(const UObject* WorldContext, TEnumAsByte<EHardwareDeviceSupportedFeatures::Type> Feature) {
    return false;
}

bool UInputContextSubsystem::HasActiveInputDeviceAudioBasedVibrationSupport(const UObject* WorldContext) {
    return false;
}

bool UInputContextSubsystem::HasActiveContextOfType(TSubclassOf<UInputContext> ContextType) {
    return false;
}

FString UInputContextSubsystem::GetRemappingSummary() {
    return TEXT("");
}

EInputDeviceType UInputContextSubsystem::GetPlatformDefaultGamepadDevice() {
    return EInputDeviceType::None;
}

UNavUserWidget* UInputContextSubsystem::GetNavUserWidgetOfTypeFromStack(TSubclassOf<UNavUserWidget> WidgetType, bool& bResult) {
    return NULL;
}

UInputDeviceMapping* UInputContextSubsystem::GetInputDeviceMapping(EInputDeviceType Type) {
    return NULL;
}

bool UInputContextSubsystem::GetHasFocus() const {
    return false;
}

UInputContainer* UInputContextSubsystem::GetCurrentTopContainer() const {
    return NULL;
}

EInputDeviceType UInputContextSubsystem::GetCurrentGamepadDevice() {
    return EInputDeviceType::None;
}

UInputContext* UInputContextSubsystem::GetContextOfType_ConsiderInheritance(TSubclassOf<UInputContext> ContextType, const UInputContext* IgnoreContext) {
    return NULL;
}

UInputContext* UInputContextSubsystem::GetContextOfType(TSubclassOf<UInputContext> ContextType, bool& bSuccess, UInputContext* IgnoreContext) {
    return NULL;
}

void UInputContextSubsystem::CallOnActiveInputDeviceChanged() {
}

void UInputContextSubsystem::AddReceiver(TScriptInterface<IInputReceiver> Receiver) {
}


