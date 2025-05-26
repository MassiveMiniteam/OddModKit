#include "AIPerceptionSimulationComponent.h"
#include "Templates/SubclassOf.h"

UAIPerceptionSimulationComponent::UAIPerceptionSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIgnoreDefaultActorClasses = true;
    this->NumFramesSinceLastUpdate = 0;
}

FFixed UAIPerceptionSimulationComponent::GetCostForTargetingActorWithAbility(const ASimulationActor* Actor, TSubclassOf<UGameplayAbility> Ability) const {
    return FFixed{};
}

ASimulationActor* UAIPerceptionSimulationComponent::GetClosestPickUpItem(TArray<UItemConfig*> OptionalWhitelist, bool bIgnoreReservedStat) const {
    return NULL;
}

ASimulationActor* UAIPerceptionSimulationComponent::GetClosestAttackableActorWithIgnoreTags(TSubclassOf<UGameplayAbility> Ability, TArray<EFactionType> OptionalFactionWhiteList, TArray<FGameplayTag> IgnoreTags, bool OnlyPrey, bool bOnlyTargetsThatAreAlreadyInCombatWithMyFaction, int32 MaxDistanceOverride) const {
    return NULL;
}

ASimulationActor* UAIPerceptionSimulationComponent::GetClosestAttackableActor(TSubclassOf<UGameplayAbility> Ability, TArray<EFactionType> OptionalFactionWhiteList, bool OnlyPrey, bool bOnlyTargetsThatAreAlreadyInCombatWithMyFaction, int32 MaxDistanceOverride) const {
    return NULL;
}

ASimulationActor* UAIPerceptionSimulationComponent::GetClosestActorThatConsidersMeAsPrey() const {
    return NULL;
}

TArray<ASimulationActor*> UAIPerceptionSimulationComponent::GetAttackableActorsInRange(int32 Range, TSubclassOf<UGameplayAbility> Ability) const {
    return TArray<ASimulationActor*>();
}

TArray<ASimulationActor*> UAIPerceptionSimulationComponent::GetAllPerceivedActors() const {
    return TArray<ASimulationActor*>();
}


