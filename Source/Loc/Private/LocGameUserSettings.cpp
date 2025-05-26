#include "LocGameUserSettings.h"

ULocGameUserSettings::ULocGameUserSettings() {
    this->LastCPUBenchmarkSteps.AddDefaulted(2);
    this->LastGPUBenchmarkSteps.AddDefaulted(7);
    this->bIsInitialSetupDone = true;
    this->VSyncType = EVSyncType::Full;
    this->AntiAliasingType = EAntiAliasingType::DLSS;
    this->DLSSMode = EDLSSMode::Balanced;
    this->FSRMode = EFSRMode::Balanced;
    this->ScreenPercentage = 58;
    this->LumenEnabled = ELumen::Off;
    this->GammaValue = 2.20f;
}

bool ULocGameUserSettings::WouldChangeRHI() {
    return false;
}

void ULocGameUserSettings::TriggerUIUpdateDelegate() {
}

void ULocGameUserSettings::SetVSyncType(EVSyncType Value) {
}

void ULocGameUserSettings::SetScreenPercentage(int32 Value) {
}

void ULocGameUserSettings::SetRenderMode(ERenderMode Value) {
}

void ULocGameUserSettings::SetLumen(ELumen Value) {
}

void ULocGameUserSettings::SetGammaValue(float Value) {
}

void ULocGameUserSettings::SetFSRMode(EFSRMode Value) {
}

void ULocGameUserSettings::SetDLSSMode(EDLSSMode Value) {
}

void ULocGameUserSettings::SetAntiAliasing(EAntiAliasingType Value) {
}

bool ULocGameUserSettings::IsLumenEnabled() {
    return false;
}

bool ULocGameUserSettings::IsDirectX12() {
    return false;
}

EVSyncType ULocGameUserSettings::GetVSyncType() {
    return EVSyncType::None;
}

FText ULocGameUserSettings::GetSupportedRHINames(ERenderMode enumInput) {
    return FText::GetEmpty();
}

TArray<ERenderMode> ULocGameUserSettings::GetSupportedRenderModes() {
    return TArray<ERenderMode>();
}

TArray<EAntiAliasingType> ULocGameUserSettings::GetSupportedAntiAliasingTypes() {
    return TArray<EAntiAliasingType>();
}

int32 ULocGameUserSettings::GetScreenPercentage() {
    return 0;
}

ERenderMode ULocGameUserSettings::GetRHIEnum() {
    return ERenderMode::Dx11;
}

ULocGameUserSettings* ULocGameUserSettings::GetLocGameUserSettings() {
    return NULL;
}

FText ULocGameUserSettings::GetIniRHI() {
    return FText::GetEmpty();
}

ERenderMode ULocGameUserSettings::GetIniEnum() {
    return ERenderMode::Dx11;
}

FText ULocGameUserSettings::GetHardwareInfo() {
    return FText::GetEmpty();
}

float ULocGameUserSettings::GetGammaValue() {
    return 0.0f;
}

EFSRMode ULocGameUserSettings::GetFSRMode() {
    return EFSRMode::Off;
}

TArray<float> ULocGameUserSettings::GetFramerateLimits() {
    return TArray<float>();
}

TArray<FText> ULocGameUserSettings::GetFramerateLimitNames() {
    return TArray<FText>();
}

FText ULocGameUserSettings::GetFramerateLimitDisplayName(float Limit) {
    return FText::GetEmpty();
}

EDLSSMode ULocGameUserSettings::GetDLSSMode() {
    return EDLSSMode::Off;
}

TArray<FText> ULocGameUserSettings::GetAntiAliasingDisplayNames() {
    return TArray<FText>();
}

FText ULocGameUserSettings::GetAntiAliasingDisplayName(EAntiAliasingType AAType) {
    return FText::GetEmpty();
}

EAntiAliasingType ULocGameUserSettings::GetAntiAliasing() {
    return EAntiAliasingType::None;
}


