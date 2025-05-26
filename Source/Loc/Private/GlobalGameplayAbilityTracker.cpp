#include "GlobalGameplayAbilityTracker.h"
#include "Templates/SubclassOf.h"

UGlobalGameplayAbilityTracker::UGlobalGameplayAbilityTracker(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UGlobalGameplayAbilityTracker::OnAbilityStarted(TSubclassOf<UGameplayAbility> Ability, ASimulationActor* Owner) {
}

UGlobalGameplayAbilityTracker* UGlobalGameplayAbilityTracker::GetGlobalAbilityTracker(const UObject* WorldContext) {
    return NULL;
}


