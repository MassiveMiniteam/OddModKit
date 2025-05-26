#include "BPFL_ActorCondition.h"
#include "Templates/SubclassOf.h"

UBPFL_ActorCondition::UBPFL_ActorCondition() {
}

bool UBPFL_ActorCondition::IsConditionFulfilled_Branched(const AActor* Actor, TSubclassOf<UActorConditionStrategy> Condition) {
    return false;
}

bool UBPFL_ActorCondition::IsConditionFulfilled(const AActor* Actor, TSubclassOf<UActorConditionStrategy> Condition) {
    return false;
}

bool UBPFL_ActorCondition::AreAllConditionsFulfilled_Branched(const AActor* Actor, TArray<TSubclassOf<UActorConditionStrategy>> Conditions) {
    return false;
}

bool UBPFL_ActorCondition::AreAllConditionsFulfilled(const AActor* Actor, TArray<TSubclassOf<UActorConditionStrategy>> Conditions) {
    return false;
}


