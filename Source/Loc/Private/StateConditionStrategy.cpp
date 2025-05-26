#include "StateConditionStrategy.h"

UStateConditionStrategy::UStateConditionStrategy() {
}

bool UStateConditionStrategy::OnCheck_Implementation(const UBaseState* InitializedState) const {
    return false;
}

bool UStateConditionStrategy::Check(const UBaseState* InitializedState) const {
    return false;
}


