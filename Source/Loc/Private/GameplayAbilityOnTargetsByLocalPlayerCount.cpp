#include "GameplayAbilityOnTargetsByLocalPlayerCount.h"
#include "Templates/SubclassOf.h"

UGameplayAbilityOnTargetsByLocalPlayerCount::UGameplayAbilityOnTargetsByLocalPlayerCount() {
    this->AbilityClassToTrack = NULL;
}

void UGameplayAbilityOnTargetsByLocalPlayerCount::TrackAbilityAndItemTargets(UObject* WorldContext, TSubclassOf<UGameplayAbility> InAbilityClass, UItemConfig* ItemTarget) {
}


