#include "GlobalGameSettings.h"

UGlobalGameSettings::UGlobalGameSettings() {
}

bool UGlobalGameSettings::SupportsAchievementUnlockFromProfileSaveGame() {
    return false;
}

bool UGlobalGameSettings::IsXboxDemoWishlistButtonSupported() {
    return false;
}

bool UGlobalGameSettings::IsVibrationSupported() {
    return false;
}

bool UGlobalGameSettings::IsTrophyTextSupported() {
    return false;
}

bool UGlobalGameSettings::IsTestBuild() {
    return false;
}

bool UGlobalGameSettings::IsSwitch() {
    return false;
}

bool UGlobalGameSettings::IsSteamDemoButtonsSupported() {
    return false;
}

bool UGlobalGameSettings::IsShowRoomSupported() {
    return false;
}

bool UGlobalGameSettings::IsShipping(bool bTestIsShipping) {
    return false;
}

bool UGlobalGameSettings::IsSendFeedbackSupported() {
    return false;
}

bool UGlobalGameSettings::IsQuitButtonSupported() {
    return false;
}

bool UGlobalGameSettings::IsPlayerListReportSupported() {
    return false;
}

bool UGlobalGameSettings::IsPlayerListProfileSupported() {
    return false;
}

bool UGlobalGameSettings::IsPlayerListKickSupported() {
    return false;
}

bool UGlobalGameSettings::IsPlatform(EPlatformType Platform) {
    return false;
}

bool UGlobalGameSettings::IsNonFixedTimestepForced() {
    return false;
}

bool UGlobalGameSettings::IsMultiplayerSupported() {
    return false;
}

bool UGlobalGameSettings::IsModdingSupported() {
    return false;
}

bool UGlobalGameSettings::IsMobile() {
    return false;
}

bool UGlobalGameSettings::IsLuna() {
    return false;
}

bool UGlobalGameSettings::IsLanguageSavedToConfig() {
    return false;
}

bool UGlobalGameSettings::IsKeyboardSupported() {
    return false;
}

bool UGlobalGameSettings::IsGraphicsSettingsSupported() {
    return false;
}

bool UGlobalGameSettings::IsGammaSettingSupported() {
    return false;
}

bool UGlobalGameSettings::IsExternalLinksSupported() {
    return false;
}

bool UGlobalGameSettings::IsEditor() {
    return false;
}

bool UGlobalGameSettings::IsDemo() {
    return false;
}

bool UGlobalGameSettings::IsChangeGamepadLayoutSupported() {
    return false;
}

bool UGlobalGameSettings::IsBackgroundSoundSupported() {
    return false;
}

bool UGlobalGameSettings::IsAnyXBox() {
    return false;
}

bool UGlobalGameSettings::IsAnyPlaystation() {
    return false;
}

bool UGlobalGameSettings::IsAnyConsoleAndShipping(bool bTestIsShipping) {
    return false;
}

bool UGlobalGameSettings::IsAnyConsole() {
    return false;
}

bool UGlobalGameSettings::IsAnalyticsSupported() {
    return false;
}

bool UGlobalGameSettings::IsAchievementUnlockToastSupported() {
    return false;
}

FString UGlobalGameSettings::GetVersionWithoutCheckinNumber() {
    return TEXT("");
}

FString UGlobalGameSettings::GetVersion() {
    return TEXT("");
}

EPlatformType UGlobalGameSettings::GetPlatform() {
    return EPlatformType::None;
}


