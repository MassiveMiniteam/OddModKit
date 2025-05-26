#include "BPFL_DifficultySettings.h"

UBPFL_DifficultySettings::UBPFL_DifficultySettings() {
}

void UBPFL_DifficultySettings::SetDifficultyValueAsBool(FDifficultySettings& Settings, FGameplayTag Tag, bool Value) {
}

void UBPFL_DifficultySettings::SetDifficultyValue(FDifficultySettings& Settings, FGameplayTag Tag, FFixed Value) {
}

void UBPFL_DifficultySettings::SetDifficultyPresetAndCleanOverwrites(FDifficultySettings& Settings, UDifficultySettingsPreset* Preset) {
}

bool UBPFL_DifficultySettings::IsDifficultyTagDisallowingAchievements(const FDifficultySettings& Settings, const FGameplayTag& Tag) {
    return false;
}

bool UBPFL_DifficultySettings::IsDifficultyTagDefined(const FDifficultySettings& Settings, FGameplayTag Tag) {
    return false;
}

bool UBPFL_DifficultySettings::IsDifficultyPresetDisallowingAchievements(const FDifficultySettings& Settings) {
    return false;
}

bool UBPFL_DifficultySettings::GetDifficultyValueAsBool(const FDifficultySettings& Settings, FGameplayTag Tag) {
    return false;
}

FFixed UBPFL_DifficultySettings::GetDifficultyValue(const FDifficultySettings& Settings, FGameplayTag Tag) {
    return FFixed{};
}

TMap<FString, FString> UBPFL_DifficultySettings::GetDifficultySettingsDump(const FDifficultySettings& Settings) {
    return TMap<FString, FString>();
}

UDifficultySettingsPreset* UBPFL_DifficultySettings::GetDifficultyPreset(const FDifficultySettings& Settings) {
    return NULL;
}


