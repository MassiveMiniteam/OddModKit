#include "BaseState.h"
#include "Templates/SubclassOf.h"

UBaseState::UBaseState() {
    this->BehaviorTree = NULL;
    this->bLoopBehavior = false;
    this->bEnableBehaviorTreeTick = true;
}

void UBaseState::SetBlackboardValueObject(FName KeyName, UObject* ObjectValue) {
}

void UBaseState::SetBlackboardValueIntVector(FName KeyName, FIntVector IntVector) {
}






void UBaseState::OnBehaviourTreeFinished(bool bIsLooping) {
}

bool UBaseState::IsEnterToThisPossible_Implementation() {
    return false;
}


UObject* UBaseState::GetBlackboardValueObject(FName KeyName) const {
    return NULL;
}

FIntVector UBaseState::GetBlackboardValueIntVector(FName KeyName) const {
    return FIntVector{};
}

bool UBaseState::CheckStateConditionStrategy(TSubclassOf<UStateConditionStrategy> Strategy) const {
    return false;
}


