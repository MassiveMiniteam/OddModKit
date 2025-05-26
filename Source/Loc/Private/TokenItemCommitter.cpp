#include "TokenItemCommitter.h"

UTokenItemCommitter::UTokenItemCommitter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TokenGenerator = NULL;
}

void UTokenItemCommitter::SetTokenGenerator(UTokenGeneratorSimulationComponent* GeneratorSimulationComponent) {
}

void UTokenItemCommitter::OnItemDecayedFunction(UItemDecayComponent* Component, UItemConfig* ItemConfig) {
}

void UTokenItemCommitter::OnDifficultySettingsChanged(UDifficultySettingsSubsystem* Subsystem) {
}

UTokenGeneratorSimulationComponent* UTokenItemCommitter::GetTokenGenerator() const {
    return NULL;
}


