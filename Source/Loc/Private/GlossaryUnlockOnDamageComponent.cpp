#include "GlossaryUnlockOnDamageComponent.h"
#include "Templates/SubclassOf.h"

UGlossaryUnlockOnDamageComponent::UGlossaryUnlockOnDamageComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CachedGlossaryAsset = NULL;
}

void UGlossaryUnlockOnDamageComponent::OnDamageApplied(TSubclassOf<UGameplayEffectDamage> Class, FFixed Amount, FGameplayTagContainer Tags) {
}


