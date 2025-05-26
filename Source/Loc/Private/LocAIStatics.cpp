#include "LocAIStatics.h"

ULocAIStatics::ULocAIStatics() {
}

void ULocAIStatics::SetValueAsIntVector(UBlackboardComponent* Blackboard, const FName& KeyName, FIntVector VectorValue) {
}

FIntVector ULocAIStatics::GetValueAsIntVector(UBlackboardComponent* Blackboard, const FName& KeyName) {
    return FIntVector{};
}

bool ULocAIStatics::GetTargetByClustering(const TArray<ASimulationActor*>& Actors, FIntVector& OutTargetPosition, int32 Range) {
    return false;
}

bool ULocAIStatics::GetIsDiggableBetweenSparkAndTargetPosition(const UObject* WorldContext, const FIntVector& Target, const FIntVector& From) {
    return false;
}


