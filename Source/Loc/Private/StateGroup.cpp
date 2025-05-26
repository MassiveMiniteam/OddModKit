#include "StateGroup.h"

UStateGroup::UStateGroup() {
}

void UStateGroup::SetBlackboardValueObject(FName KeyName, UObject* ObjectValue) {
}

void UStateGroup::SetBlackboardValueIntVector(FName KeyName, FIntVector IntVector) {
}






void UStateGroup::OnBehaviourTreeFinished(bool bIsLooping) {
}

UObject* UStateGroup::GetBlackboardValueObject(FName KeyName) const {
    return NULL;
}

FIntVector UStateGroup::GetBlackboardValueIntVector(FName KeyName) const {
    return FIntVector{};
}


