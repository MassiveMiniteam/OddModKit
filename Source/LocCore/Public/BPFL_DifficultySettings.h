#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "DifficultySettings.h"
#include "Fixed.h"
#include "BPFL_DifficultySettings.generated.h"

class UDifficultySettingsPreset;

UCLASS(Blueprintable)
class LOCCORE_API UBPFL_DifficultySettings : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UBPFL_DifficultySettings();

    UFUNCTION(BlueprintCallable)
    static void SetDifficultyValueAsBool(UPARAM(Ref) FDifficultySettings& Settings, FGameplayTag Tag, bool Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetDifficultyValue(UPARAM(Ref) FDifficultySettings& Settings, FGameplayTag Tag, FFixed Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetDifficultyPresetAndCleanOverwrites(UPARAM(Ref) FDifficultySettings& Settings, UDifficultySettingsPreset* Preset);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsDifficultyTagDisallowingAchievements(const FDifficultySettings& Settings, const FGameplayTag& Tag);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsDifficultyTagDefined(const FDifficultySettings& Settings, FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsDifficultyPresetDisallowingAchievements(const FDifficultySettings& Settings);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetDifficultyValueAsBool(const FDifficultySettings& Settings, FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed GetDifficultyValue(const FDifficultySettings& Settings, FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    static TMap<FString, FString> GetDifficultySettingsDump(const FDifficultySettings& Settings);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UDifficultySettingsPreset* GetDifficultyPreset(const FDifficultySettings& Settings);
    
};

