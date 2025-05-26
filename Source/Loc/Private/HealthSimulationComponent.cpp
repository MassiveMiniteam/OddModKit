#include "HealthSimulationComponent.h"
#include "Templates/SubclassOf.h"

UHealthSimulationComponent::UHealthSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool UHealthSimulationComponent::TryApplyDamage(TSubclassOf<UGameplayEffectDamage> DamageClass, FFixed Amount, FGameplayTagContainer Tags, AActor* Instigator) {
    return false;
}

void UHealthSimulationComponent::OnDifficultySettingsChanged(UDifficultySettingsSubsystem* Subsystem) {
}

TArray<FSingleDamageTrackData> UHealthSimulationComponent::GetTrackedDamageDataStack() {
    return TArray<FSingleDamageTrackData>();
}

FFixed UHealthSimulationComponent::GetMaxHealth() const {
    return FFixed{};
}

FFixed UHealthSimulationComponent::GetCurrentHealthInPercent() const {
    return FFixed{};
}

FFixed UHealthSimulationComponent::GetCurrentHealth() const {
    return FFixed{};
}


