#include "LocUpscalingSubsystem.h"

ULocUpscalingSubsystem::ULocUpscalingSubsystem() {
}

bool ULocUpscalingSubsystem::IsDLSSSupported() {
    return false;
}

bool ULocUpscalingSubsystem::IsDLSSModeSupported(EDLSSMode DLSSMode) {
    return false;
}

bool ULocUpscalingSubsystem::IsDLSSEnabled() {
    return false;
}

TArray<EDLSSMode> ULocUpscalingSubsystem::GetSupportedDLSSModes() {
    return TArray<EDLSSMode>();
}

void ULocUpscalingSubsystem::GetDLSSScreenPercentageRange(float& MinScreenPercentage, float& MaxScreenPercentage) {
}

void ULocUpscalingSubsystem::GetDLSSModeInformation(EDLSSMode DLSSMode, FVector2D ScreenResolution, bool& bIsSupported, float& OptimalScreenPercentage, bool& bIsFixedScreenPercentage, float& MinScreenPercentage, float& MaxScreenPercentage, float& OptimalSharpness) {
}

FText ULocUpscalingSubsystem::GetDLSSModeDisplayName(EDLSSMode DLSSMode) {
    return FText::GetEmpty();
}

void ULocUpscalingSubsystem::EnableDLSS(bool bIsEnabled) {
}

void ULocUpscalingSubsystem::ApplyUpscalingSettings() {
}


