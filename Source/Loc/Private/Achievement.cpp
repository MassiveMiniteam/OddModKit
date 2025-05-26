#include "Achievement.h"

UAchievement::UAchievement() {
    this->AchievementOrderInUI = 0;
    this->bShowNeededAmount = false;
    this->bIsUnlocked = false;
}

void UAchievement::Unlock(UObject* WorldContext) {
}

void UAchievement::Reset(UObject* WorldContext, bool bSave) {
}

bool UAchievement::IsUnlocked(UObject* WorldContext) {
    return false;
}

float UAchievement::GetPercentage(UObject* WorldContext) {
    return 0.0f;
}

int32 UAchievement::GetNeededAmount(UObject* WorldContext) {
    return 0;
}

int32 UAchievement::GetCurrentAmount(UObject* WorldContext) {
    return 0;
}

bool UAchievement::GetAreAchievementsAllowed(const UObject* WorldContext) {
    return false;
}

bool UAchievement::CanUnlock(UObject* WorldContext) {
    return false;
}


