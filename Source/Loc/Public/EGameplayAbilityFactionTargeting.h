#pragma once
#include "CoreMinimal.h"
#include "EGameplayAbilityFactionTargeting.generated.h"

UENUM(BlueprintType)
enum class EGameplayAbilityFactionTargeting : uint8 {
    AttackableFaction,
    OwnFaction,
    EveryFaction,
};

