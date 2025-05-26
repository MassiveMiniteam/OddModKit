#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/SaveGame.h"
#include "GameplayTagContainer.h"
#include "EAudioVolumeType.h"
#include "ERefreshRate.h"
#include "GlobalSettingsBoolChangedDelegate.h"
#include "InputActionKeyReMapping.h"
#include "ModSettingsItem.h"
#include "SavedCameraSetupSave.h"
#include "LocGlobalSettingsSave.generated.h"

class UInputActionData;
class UTutorialHintData;

UCLASS(Blueprintable)
class LOC_API ULocGlobalSettingsSave : public USaveGame {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalSettingsBoolChanged OnShowPlayerNamesChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bShowUntranslatedDialogs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bEnableAnalytics;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bUseHoldForCursor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bDynamicCompass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bShowEditToolButtonPrompts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bShowAimModeButtonPrompts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bEnableControllerVibration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bEnableFallingParticles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bEnableAudioFromController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bEnableControllerLightBar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bEnableAdaptiveTriggers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float VibrationIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float CameraSensitivity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bShowPlayerNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float UnfocusedVolumeMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float MasterVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float MusicVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float SFXVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float AmbienceVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float WorkstationsVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float MinionsVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float UIScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float ScreenShakeIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bForceAccurateTimestep;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 TimeStepBudgetInMilliseconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString UserEmail;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bStartGameWithTutorial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bShowBiomeIntros;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bShowRecentlyUnlockedNotifications;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UTutorialHintData>> SeenTutorialHints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FSavedCameraSetupSave SavedCameraSetup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DialogueTextSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 AutosaveIntervalInMinutes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 NumberOfFractionDigits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayTag MultiplayerPresence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ERefreshRate DisplayModeSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FInputActionKeyReMapping> UsedInputActionKeyReMapping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float MinimapScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FString> EnabledMods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FModSettingsItem> ModSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString ConsoleCulture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bXboxButtonLayout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bEnableMisophonia;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bEnableMisophoniaElectric;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsInitialSetupDone;
    
    ULocGlobalSettingsSave();

    UFUNCTION(BlueprintCallable)
    void SetVolume(EAudioVolumeType AudioVolumeType, float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetUnfocusedVolumeMultiplier(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetShowPlayerNames(bool bInValue);
    
    UFUNCTION(BlueprintCallable)
    void SetInputActionKeyReMapping(TArray<UInputActionData*> RegisteredData, UInputActionData* Data, FInputActionKeyMapping Key, bool IsGamepad);
    
    UFUNCTION(BlueprintCallable)
    void LoadKeyReMappingsToInputActionData();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetVolume(EAudioVolumeType AudioVolumeType);
    
    UFUNCTION(BlueprintCallable)
    TMap<FString, FString> GetSettingsDump();
    
    UFUNCTION(BlueprintCallable)
    void EmptyInputActionKeyReMapping(TArray<UInputActionData*> RegisteredData, bool IsGamepad);
    
    UFUNCTION(BlueprintCallable)
    void ClearGamepadInputActionKeyReMapping(UInputActionData* Data, bool IsGamepad);
    
    UFUNCTION(BlueprintCallable)
    void ApplyLunaGraphicSettings();
    
    UFUNCTION(BlueprintCallable)
    void ApplyConsoleLanguageSettings();
    
};

