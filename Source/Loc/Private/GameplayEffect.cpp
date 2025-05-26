#include "GameplayEffect.h"

UGameplayEffect::UGameplayEffect() {
    this->bEnableTick = true;
    this->bShouldBeVisualizedSequentially = false;
    this->bIsStarted = false;
    this->StackingPolicy = EGameplayEffectStackingPolicy::CreateNewInstance;
    this->SuccessionPolicy = EGameplayEffectSuccessionPolicy::Always;
    this->CurrentNumStacks = 1;
    this->NumMaxStacks = 1;
    this->ApplicationProbability = 100;
}


void UGameplayEffect::StopEffectWithReason(EDestructionReason Reason) {
}

void UGameplayEffect::StopEffect() {
}

void UGameplayEffect::SetInstigator(ASimulationActor* InstigatorIn) {
}


void UGameplayEffect::OnStopEffectWithReason_Native(EDestructionReason Reason) {
}





void UGameplayEffect::OnSimulationActorShutDown(ASimulationActor* SimulationActor, EDestructionReason Reason) {
}


bool UGameplayEffect::IsInstantEffect() const {
    return false;
}

bool UGameplayEffect::IsInSpecificTimeWindow(FFixed TimeWindowStart, FFixed TimeWindowEnd) const {
    return false;
}

bool UGameplayEffect::IsInSpecificFrameTime(FFixed Time, FFixed DeltaTime) const {
    return false;
}

bool UGameplayEffect::IsInfiniteEffect() const {
    return false;
}

EGameplayEffectStackingPolicy UGameplayEffect::GetStackingPolicy() const {
    return EGameplayEffectStackingPolicy::CreateNewInstance;
}

FFixed UGameplayEffect::GetRelativeStackAmount() const {
    return FFixed{};
}

AActor* UGameplayEffect::GetPresentationActor(EValidityState& ValidityState) const {
    return NULL;
}

int32 UGameplayEffect::GetNumMaxStacks_Implementation(UStatsComponent* TargetStats) const {
    return 0;
}

int32 UGameplayEffect::GetNumCurrentStacks() const {
    return 0;
}

TMap<FGameplayTag, FGameplayStatModifierArray> UGameplayEffect::GetModifiers() const {
    return TMap<FGameplayTag, FGameplayStatModifierArray>();
}

ASimulationActor* UGameplayEffect::GetInstigator() {
    return NULL;
}

void UGameplayEffect::ChangeNumStacks(int32 NewNumStacks) {
}

bool UGameplayEffect::CanApplyEffect_Implementation(UStatsComponent* StatsComponent) {
    return false;
}


