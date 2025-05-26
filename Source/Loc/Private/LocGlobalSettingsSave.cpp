#include "LocGlobalSettingsSave.h"

ULocGlobalSettingsSave::ULocGlobalSettingsSave() {
    this->bShowUntranslatedDialogs = false;
    this->bEnableAnalytics = true;
    this->bUseHoldForCursor = true;
    this->bDynamicCompass = true;
    this->bShowEditToolButtonPrompts = true;
    this->bShowAimModeButtonPrompts = true;
    this->bEnableControllerVibration = false;
    this->bEnableFallingParticles = true;
    this->bEnableAudioFromController = false;
    this->bEnableControllerLightBar = false;
    this->bEnableAdaptiveTriggers = false;
    this->VibrationIntensity = 0.70f;
    this->CameraSensitivity = 1.00f;
    this->bShowPlayerNames = true;
    this->UnfocusedVolumeMultiplier = 0.00f;
    this->MasterVolume = 1.00f;
    this->MusicVolume = 1.00f;
    this->SFXVolume = 1.00f;
    this->AmbienceVolume = 1.00f;
    this->WorkstationsVolume = 1.00f;
    this->MinionsVolume = 1.00f;
    this->UIScale = 1.00f;
    this->ScreenShakeIntensity = 1.00f;
    this->bForceAccurateTimestep = true;
    this->TimeStepBudgetInMilliseconds = 4;
    this->bStartGameWithTutorial = true;
    this->bShowBiomeIntros = false;
    this->bShowRecentlyUnlockedNotifications = true;
    this->DialogueTextSpeed = 1.00f;
    this->AutosaveIntervalInMinutes = 10;
    this->NumberOfFractionDigits = 1;
    this->DisplayModeSettings = ERefreshRate::RefreshRate_60Hz;
    this->MinimapScale = 1.00f;
    this->bXboxButtonLayout = true;
    this->bEnableMisophonia = false;
    this->bEnableMisophoniaElectric = false;
    this->bIsInitialSetupDone = false;
}

void ULocGlobalSettingsSave::SetVolume(EAudioVolumeType AudioVolumeType, float Value) {
}

void ULocGlobalSettingsSave::SetUnfocusedVolumeMultiplier(float Value) {
}

void ULocGlobalSettingsSave::SetShowPlayerNames(bool bInValue) {
}

void ULocGlobalSettingsSave::SetInputActionKeyReMapping(TArray<UInputActionData*> RegisteredData, UInputActionData* Data, FInputActionKeyMapping Key, bool IsGamepad) {
}

void ULocGlobalSettingsSave::LoadKeyReMappingsToInputActionData() {
}

float ULocGlobalSettingsSave::GetVolume(EAudioVolumeType AudioVolumeType) {
    return 0.0f;
}

TMap<FString, FString> ULocGlobalSettingsSave::GetSettingsDump() {
    return TMap<FString, FString>();
}

void ULocGlobalSettingsSave::EmptyInputActionKeyReMapping(TArray<UInputActionData*> RegisteredData, bool IsGamepad) {
}

void ULocGlobalSettingsSave::ClearGamepadInputActionKeyReMapping(UInputActionData* Data, bool IsGamepad) {
}

void ULocGlobalSettingsSave::ApplyLunaGraphicSettings() {
}

void ULocGlobalSettingsSave::ApplyConsoleLanguageSettings() {
}


