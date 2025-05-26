#include "GameplayEffectSingletonInstancesSubsystem.h"
#include "Templates/SubclassOf.h"

UGameplayEffectSingletonInstancesSubsystem::UGameplayEffectSingletonInstancesSubsystem() {
}

UGameplayEffect* UGameplayEffectSingletonInstancesSubsystem::GetOrCreate(TSubclassOf<UGameplayEffect> Type) {
    return NULL;
}


