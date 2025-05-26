#include "DifficultySettingsSubsystem.h"

UDifficultySettingsSubsystem::UDifficultySettingsSubsystem() {
}

bool UDifficultySettingsSubsystem::GetDifficultyValueAsBool(FGameplayTag Tag) const {
    return false;
}

FFixed UDifficultySettingsSubsystem::GetDifficultyValue(FGameplayTag Tag) const {
    return FFixed{};
}

FDifficultySettings UDifficultySettingsSubsystem::GetDifficultySettings() const {
    return FDifficultySettings{};
}


