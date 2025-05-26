#include "GameplayAbilityMultiability.h"
#include "Templates/SubclassOf.h"

UGameplayAbilityMultiability::UGameplayAbilityMultiability() {
    this->ActiveAbility = NULL;
    this->NextAbilityClass = NULL;
    this->AbilityCounter = 0;
}

void UGameplayAbilityMultiability::OnActiveAbilityFinished() {
}

TSubclassOf<UGameplayAbility> UGameplayAbilityMultiability::GetNextAbility() const {
    return NULL;
}


