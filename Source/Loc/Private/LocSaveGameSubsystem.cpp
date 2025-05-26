#include "LocSaveGameSubsystem.h"

ULocSaveGameSubsystem::ULocSaveGameSubsystem() {
    this->bIsGlobalSaveGameSavable = true;
    this->GlobalSaveGameName = TEXT("SaveGames");
    this->GlobalSettingsSaveName = TEXT("Settings");
    this->GlobalProfileSaveName = TEXT("Profile");
    this->ChunkPrefix = TEXT("chunk");
    this->Chunk0Prefix = TEXT("chunk0_");
    this->GlobalSaveGame = NULL;
    this->GlobalSettingsSave = NULL;
    this->GlobalProfileSave = NULL;
    this->MaxSaveGames = -1;
    this->AutosaveSlots = 3;
    this->bIsFirstGameStart = true;
}

void ULocSaveGameSubsystem::WriteToMMTSaveGameFolder(UObject* WorldContext, ULocSaveGame* SaveGame, const FString& Filename) {
}

void ULocSaveGameSubsystem::StoreSaveGameAsAsset(UObject* WorldContext, ULocSaveGame* SaveGame, const FString& Filename) {
}

void ULocSaveGameSubsystem::SaveGlobalSettings() {
}

void ULocSaveGameSubsystem::SaveGlobalSaveGame() {
}

void ULocSaveGameSubsystem::SaveGlobalProfile() {
}

void ULocSaveGameSubsystem::SaveGameToSlot(const FString& SlotName, ULocSaveGame* SaveGame, FSaveGameSavedEvent OnSaved) {
}

void ULocSaveGameSubsystem::SaveDummySavegame(const FString& SlotName, int32 ByteSize) {
}

void ULocSaveGameSubsystem::ReadMMTCloudSaveGameNames(const FMMTCloudSavegamesFoundEvent& Result) {
}

void ULocSaveGameSubsystem::OverrideSaveGameToSlot(const FString& SlotName, const FString& NewSlotName, ULocSaveGame* SaveGame, FSaveGameSavedEvent OnSaved) {
}

void ULocSaveGameSubsystem::LoadSaveGame(const FString& SlotName, FSaveGameLoadedEvent OnSaveGameLoaded) {
}

void ULocSaveGameSubsystem::LoadMMTCloudSaveGame(UObject* WorldContext, const FString& SaveGameName) {
}

void ULocSaveGameSubsystem::LoadMetaSaveGames() {
}

void ULocSaveGameSubsystem::LoadGlobalSaveGame() {
}

void ULocSaveGameSubsystem::InitializeGlobalSaveGame() {
}

int32 ULocSaveGameSubsystem::GetSaveGameCount() {
    return 0;
}

ULocMetaSaveGame* ULocSaveGameSubsystem::GetOldestAutosaveOrNew() {
    return NULL;
}

ULocMetaSaveGame* ULocSaveGameSubsystem::GetMetaForSaveSlot(const FString& SlotName) const {
    return NULL;
}

int32 ULocSaveGameSubsystem::GetMaxSaveGameCount() const {
    return 0;
}

TMap<FString, ULocMetaSaveGame*> ULocSaveGameSubsystem::GetListOfSaveGames() {
    return TMap<FString, ULocMetaSaveGame*>();
}

TArray<FString> ULocSaveGameSubsystem::GetListOfSaveGameNamesSorted(bool bIncludeAutosaves) {
    return TArray<FString>();
}

bool ULocSaveGameSubsystem::GetLastLoadedSaveGameName(FString& SlotName) {
    return false;
}

FString ULocSaveGameSubsystem::GetIncrementedSaveSlotName(UObject* WorldContext, const FString& Filename, const FString& Delimiter) {
    return TEXT("");
}

ULocGlobalSettingsSave* ULocSaveGameSubsystem::GetGlobalSettings() const {
    return NULL;
}

ULocGlobalProfileSave* ULocSaveGameSubsystem::GetGlobalProfile() const {
    return NULL;
}

FString ULocSaveGameSubsystem::GetAutosaveNameForSlot(int32 Slot) {
    return TEXT("");
}

TArray<ULocMetaSaveGame*> ULocSaveGameSubsystem::GetAutosaveMetas() {
    return TArray<ULocMetaSaveGame*>();
}

bool ULocSaveGameSubsystem::DoesSaveGameExist(const FString& SlotName) const {
    return false;
}

void ULocSaveGameSubsystem::DeleteSaveGame(const FString& SlotName) {
}

ULocMetaSaveGame* ULocSaveGameSubsystem::CreateNewMetaSaveGame(const FString& SlotName, bool bIsAutosave) {
    return NULL;
}

void ULocSaveGameSubsystem::CheckSaveGameModCompatibility(UObject* WorldContext, const FString& SlotName, FModdingCompatibilityEvent OnResult) {
}

void ULocSaveGameSubsystem::Autosave(ULocSaveGame* SaveGame) {
}

void ULocSaveGameSubsystem::ApplyLoadedGlobalSettings() {
}

void ULocSaveGameSubsystem::ApplyLoadedGlobalProfile() {
}


