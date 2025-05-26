#include "GameplayAbility.h"
#include "GameplayAbilityTargeting_SingleTarget.h"
#include "Templates/SubclassOf.h"

UGameplayAbility::UGameplayAbility() {
    this->TargetingClass = UGameplayAbilityTargeting_SingleTarget::StaticClass();
    this->TargetingEffectClassOverride = NULL;
    this->bMoveTowardsTargetActor = true;
    this->bSnapRotationToTargetOnStart = true;
    this->bSnapRotationToTargetOnTick = false;
    this->bAutoStartAnimation = true;
}

void UGameplayAbility::StartAbilityAnimation() {
}


void UGameplayAbility::OnAbilityExecuted_Native(const TArray<ASimulationActor*>& TargetsHit) {
}


TArray<ASimulationActor*> UGameplayAbility::GetTargetsByStrategy(TSubclassOf<UGameplayAbilityTargeting> Strategy) const {
    return TArray<ASimulationActor*>();
}

TArray<ASimulationActor*> UGameplayAbility::GetTargets() const {
    return TArray<ASimulationActor*>();
}

void UGameplayAbility::CancelAbility(FFixed LoopDelta) {
}


