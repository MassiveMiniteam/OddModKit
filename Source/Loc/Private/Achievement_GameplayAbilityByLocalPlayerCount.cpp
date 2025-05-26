#include "Achievement_GameplayAbilityByLocalPlayerCount.h"
#include "Templates/SubclassOf.h"

UAchievement_GameplayAbilityByLocalPlayerCount::UAchievement_GameplayAbilityByLocalPlayerCount() {
    this->AbilityClassToTrack = NULL;
}

void UAchievement_GameplayAbilityByLocalPlayerCount::TrackAbility(UObject* WorldContext, TSubclassOf<UGameplayAbility> InAbilityClass, ASimulationActor* MinionOwningActor) {
}

bool UAchievement_GameplayAbilityByLocalPlayerCount::CanBeTracked(UObject* WorldContext, ASimulationActor* MinionOwningActor) {
    return false;
}


