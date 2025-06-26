#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EPlatformType.h"
#include "GlobalGameSettings.generated.h"

UCLASS(Blueprintable)
class LOCCORE_API UGlobalGameSettings : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UGlobalGameSettings();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool SupportsAchievementUnlockFromProfileSaveGame();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsXboxDemoWishlistButtonSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsVibrationSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsTrophyTextSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsTestBuild();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSwitch();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSteamDemoButtonsSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsShowRoomSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsShipping(bool bTestIsShipping);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSendFeedbackSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsQuitButtonSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlayerListReportSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlayerListProfileSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlayerListKickSupported();
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlatform(EPlatformType Platform);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsNonFixedTimestepForced();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsMultiplayerSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsModdingSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsMobile();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsLuna();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsLanguageSavedToConfig();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsKeyboardSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsGraphicsSettingsSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsGammaSettingSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsExternalLinksSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsEditor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsDemo();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsChangeGamepadLayoutSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsBackgroundSoundSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsAnyXBox();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsAnyPlaystation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsAnyConsoleAndShipping(bool bTestIsShipping);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsAnyConsole();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsAnalyticsSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsAchievementUnlockToastSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetVersionWithoutCheckinNumber();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetVersion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EPlatformType GetPlatform();
    
};

