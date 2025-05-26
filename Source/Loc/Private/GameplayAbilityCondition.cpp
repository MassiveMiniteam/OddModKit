#include "GameplayAbilityCondition.h"
#include "Templates/SubclassOf.h"

UGameplayAbilityCondition::UGameplayAbilityCondition() {
}

bool UGameplayAbilityCondition::IsFulfilled_Implementation(const UGameplayAbilityComponent* GameplayAbilityComponent, TSubclassOf<UGameplayAbility> GameplayAbility) const {
    return false;
}


