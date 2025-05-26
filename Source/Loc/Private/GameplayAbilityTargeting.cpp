#include "GameplayAbilityTargeting.h"
#include "Templates/SubclassOf.h"

UGameplayAbilityTargeting::UGameplayAbilityTargeting() {
    this->SelfTargeting = EGameplayAbilitySelfTargeting::No;
    this->FactionTargeting = EGameplayAbilityFactionTargeting::AttackableFaction;
    this->MaxUnitsHit = -1;
    this->bDrawAreaOfEffect = false;
    this->bSortTargetsByAITargetingPriorityStat = false;
}


TArray<ASimulationActor*> UGameplayAbilityTargeting::GetCurrentTargets(ASimulationActor* AbilityUser, TSubclassOf<UGameplayAbility> GameplayAbilityClass) const {
    return TArray<ASimulationActor*>();
}

TArray<ASimulationActor*> UGameplayAbilityTargeting::GetAllTargetActorsByRelevantLocation_Implementation(const ASimulationActor* AbilityUser, TSubclassOf<UGameplayAbility> GameplayAbilityClass) const {
    return TArray<ASimulationActor*>();
}


