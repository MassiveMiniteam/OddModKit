#include "LocGameplaySubsystem.h"
#include "Templates/SubclassOf.h"

ULocGameplaySubsystem::ULocGameplaySubsystem() {
    this->ItemConfigLibrary = NULL;
    this->ConstructableConfigLibrary = NULL;
    this->GlobalClassMappings = NULL;
    this->GrassSimulationActor = NULL;
}

void ULocGameplaySubsystem::UnregisterWidgetHook(UClass* Class, TSubclassOf<UWidgetHook> Hook) {
}

void ULocGameplaySubsystem::RegisterWidgetHook(UClass* Class, TSubclassOf<UWidgetHook> Hook) {
}

void ULocGameplaySubsystem::OnModsChanged() {
}

TArray<TSubclassOf<UWidgetHook>> ULocGameplaySubsystem::GetWidgetHooks(UClass* Class) {
    return TArray<TSubclassOf<UWidgetHook>>();
}

TArray<UUnlockableDataAsset*> ULocGameplaySubsystem::GetAllUnlockableDataAssets(const UObject* WorldContext, FGameplayTagContainer RequiredTags, FGameplayTagContainer ForbiddenTags) {
    return TArray<UUnlockableDataAsset*>();
}


