#include "ModdingSubsystem.h"

UModdingSubsystem::UModdingSubsystem() {
}

void UModdingSubsystem::StopPlaytimeTracking() {
}

void UModdingSubsystem::StartPlaytimeTracking() {
}

void UModdingSubsystem::RefreshMods() {
}

void UModdingSubsystem::OpenWorkshop() {
}

bool UModdingSubsystem::IsDisallowingAchievements() const {
    return false;
}

bool UModdingSubsystem::HasEnabledMods() const {
    return false;
}

UModInstance* UModdingSubsystem::GetModInstanceForShortManifest(FModManifestShort Manifest) {
    return NULL;
}

FString UModdingSubsystem::GetModdingDirectory() const {
    return TEXT("");
}

TArray<FModDependencyError> UModdingSubsystem::GetModDependencies(UModInstance* ModInstance, bool bToEnable, TArray<UModInstance*>& Dependencies, bool bUseOverrides, TArray<UModInstance*> EnableModIdOverride, TArray<UModInstance*> DisableModIdOverride) {
    return TArray<FModDependencyError>();
}

TArray<FString> UModdingSubsystem::GetModdedLanguages() {
    return TArray<FString>();
}

void UModdingSubsystem::EnableMod(UModInstance* Mod) {
}

void UModdingSubsystem::DisableMod(UModInstance* Mod) {
}

void UModdingSubsystem::ChangeMods(TArray<UModInstance*> EnableMods, TArray<UModInstance*> DisableMods) {
}


