#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ModDependencyError.h"
#include "ModManifestShort.h"
#include "OnEnabledModsChangedDelegate.h"
#include "ModdingSubsystem.generated.h"

class UModInstance;

UCLASS(Blueprintable)
class LOC_API UModdingSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnEnabledModsChanged OnModsChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UModInstance*> Mods;
    
    UModdingSubsystem();

    UFUNCTION(BlueprintCallable)
    void StopPlaytimeTracking();
    
    UFUNCTION(BlueprintCallable)
    void StartPlaytimeTracking();
    
    UFUNCTION(BlueprintCallable)
    void RefreshMods();
    
    UFUNCTION(BlueprintCallable)
    void OpenWorkshop();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDisallowingAchievements() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasEnabledMods() const;
    
    UFUNCTION(BlueprintCallable)
    UModInstance* GetModInstanceForShortManifest(FModManifestShort Manifest);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetModdingDirectory() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<FModDependencyError> GetModDependencies(UModInstance* ModInstance, bool bToEnable, UPARAM(Ref) TArray<UModInstance*>& Dependencies, bool bUseOverrides, TArray<UModInstance*> EnableModIdOverride, TArray<UModInstance*> DisableModIdOverride);
    
    UFUNCTION(BlueprintCallable)
    TArray<FString> GetModdedLanguages();
    
    UFUNCTION(BlueprintCallable)
    void EnableMod(UModInstance* Mod);
    
    UFUNCTION(BlueprintCallable)
    void DisableMod(UModInstance* Mod);
    
    UFUNCTION(BlueprintCallable)
    void ChangeMods(TArray<UModInstance*> EnableMods, TArray<UModInstance*> DisableMods);
    
};

