#include "Achievement_GameplayAbilityOnEnemiesByLocalPlayerCount.h"
#include "Templates/SubclassOf.h"

UAchievement_GameplayAbilityOnEnemiesByLocalPlayerCount::UAchievement_GameplayAbilityOnEnemiesByLocalPlayerCount() {
    this->AbilityClassToTrack = NULL;
}

void UAchievement_GameplayAbilityOnEnemiesByLocalPlayerCount::TrackAbilityAndEnemyTargets(UObject* WorldContext, TSubclassOf<UGameplayAbility> InAbilityClass, ASimulationActor* EnemyTarget) {
}


