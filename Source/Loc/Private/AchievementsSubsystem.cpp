#include "AchievementsSubsystem.h"

UAchievementsSubsystem::UAchievementsSubsystem() {
    this->CurrentSaveDelay = 300.00f;
}

void UAchievementsSubsystem::SetAchievementsAllowed(bool bAllowed) {
}

void UAchievementsSubsystem::ResetAllAchievements_Debug() {
}

void UAchievementsSubsystem::ResetAllAchievements() {
}

void UAchievementsSubsystem::QueryAchievements() {
}

int32 UAchievementsSubsystem::GetUnlockedAchievementsCount() {
    return 0;
}

bool UAchievementsSubsystem::GetAreAchievementsAllowed() const {
    return false;
}

TArray<UAchievement*> UAchievementsSubsystem::GetAllAchievements() {
    return TArray<UAchievement*>();
}


