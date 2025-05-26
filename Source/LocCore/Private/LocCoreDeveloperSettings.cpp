#include "LocCoreDeveloperSettings.h"

ULocCoreDeveloperSettings::ULocCoreDeveloperSettings() {
    this->bUseGlobalInvalidation = false;
    this->UIDescription_VersionMismatch = FText::FromString(TEXT("Version Mismatch"));
    this->Description_GenericError = FText::FromString(TEXT("Sorry, the game is experiencing an error.\nThe error code is:"));
    this->Title_GenericError = FText::FromString(TEXT("Error!"));
    this->UIDescription_ConnectionLoss = FText::FromString(TEXT("Connection Lost"));
    this->UIDescription_TimeOut = FText::FromString(TEXT("Failed to Connect: Connection Timed Out"));
    this->UIDescription_Desync = FText::FromString(TEXT("Connection Desynced"));
    this->Title_RoomCodeError = FText::FromString(TEXT("No session with this room code was found."));
    this->Title_SessionCreationFail = FText::FromString(TEXT("Error!"));
    this->SessionCreationFail = FText::FromString(TEXT("Failed to create session - Other players will not be able to join."));
    this->Title_ErrorHostInIntro = FText::FromString(TEXT("Cannot Join - Host must finish intro cutscene before others can join."));
    this->Title_Host = FText::FromString(TEXT("Host"));
    this->Title_SendingFailed = FText::FromString(TEXT("Sending Failed"));
    this->UIDescription_HostClosedSession = FText::FromString(TEXT("Session Closed By Host"));
    this->UIDescription_Kick_ModsIncompatible = FText::FromString(TEXT("The savefile was created with mods that are not installed: "));
    this->UIDescription_Crash_Mods = FText::FromString(TEXT("Mods were disabled because of a crash in the previous session."));
    this->UITitle_ErrorKicked = FText::FromString(TEXT("Kicked by host."));
    this->Title_None = FText::FromString(TEXT("None"));
    this->PrePooledSimulationActors.AddDefaulted(6);
    this->UserPrivileges.AddDefaulted(2);
}


