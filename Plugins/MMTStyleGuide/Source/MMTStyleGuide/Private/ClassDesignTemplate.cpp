#include "ClassDesignTemplate.h"

UClassDesignTemplate::UClassDesignTemplate(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SomeValue = 0;
    this->Cooldown = 10.00f;
    this->LocalDuration = 0.00f;
    this->bTimerStarted = false;
}

void UClassDesignTemplate::SomeFunctionBoundToSomeDelegate() {
}

void UClassDesignTemplate::SecondaryInteraction(const TArray<float>& PossiblyLargeArray) {
}

void UClassDesignTemplate::PrimaryInteraction(float Parameter) {
}

TArray<float> UClassDesignTemplate::GetterThatDoesALotOfCalculations() const {
    return TArray<float>();
}

float UClassDesignTemplate::GetLocalDuration() const {
    return 0.0f;
}


