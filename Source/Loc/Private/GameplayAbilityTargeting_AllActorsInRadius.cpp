#include "GameplayAbilityTargeting_AllActorsInRadius.h"

UGameplayAbilityTargeting_AllActorsInRadius::UGameplayAbilityTargeting_AllActorsInRadius() {
    this->Radius = 800;
    this->AddOwnRadius = true;
}

void UGameplayAbilityTargeting_AllActorsInRadius::GetTargetLocationAndRadius(const AActor* AbilityUser, FIntVector& LocationOut, int32& RadiusOut) const {
}


