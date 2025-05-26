#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MMTCloudSavegamesFoundEventDelegate.h"
#include "ModdingCompatibilityEventDelegate.h"
#include "OnSavegamesChangedEventDelegate.h"
#include "SaveGameLoadedEventDelegate.h"
#include "SaveGameSavedEventDelegate.h"
#include "SettingsLoadedEvent_DynamicDelegate.h"
#include "LocSaveGameSubsystem.generated.h"

class ULocGlobalProfileSave;
class ULocGlobalSaveGame;
class ULocGlobalSettingsSave;
class ULocMetaSaveGame;
class ULocSaveGame;
class UObject;

UCLASS(Blueprintable)
class LOC_API ULocSaveGameSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsGlobalSaveGameSavable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString GlobalSaveGameName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString GlobalSettingsSaveName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString GlobalProfileSaveName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ChunkPrefix;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Chunk0Prefix;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULocGlobalSaveGame* GlobalSaveGame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULocGlobalSettingsSave* GlobalSettingsSave;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULocGlobalProfileSave* GlobalProfileSave;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, ULocMetaSaveGame*> MetaSaveGames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FAssetData> DebugSaveGames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ULocMetaSaveGame*> AutosaveMetas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxSaveGames;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSettingsLoadedEvent_Dynamic OnSettingsLoaded_Dynamic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AutosaveSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsFirstGameStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSavegamesChangedEvent OnSavegamesChanged;
    
    ULocSaveGameSubsystem();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void WriteToMMTSaveGameFolder(UObject* WorldContext, ULocSaveGame* SaveGame, const FString& Filename);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void StoreSaveGameAsAsset(UObject* WorldContext, ULocSaveGame* SaveGame, const FString& Filename);
    
    UFUNCTION(BlueprintCallable)
    void SaveGlobalSettings();
    
private:
    UFUNCTION(BlueprintCallable)
    void SaveGlobalSaveGame();
    
public:
    UFUNCTION(BlueprintCallable)
    void SaveGlobalProfile();
    
    UFUNCTION(BlueprintCallable)
    void SaveGameToSlot(const FString& SlotName, ULocSaveGame* SaveGame, FSaveGameSavedEvent OnSaved);
    
    UFUNCTION(BlueprintCallable)
    void SaveDummySavegame(const FString& SlotName, int32 ByteSize);
    
    UFUNCTION(BlueprintCallable)
    void ReadMMTCloudSaveGameNames(const FMMTCloudSavegamesFoundEvent& Result);
    
    UFUNCTION(BlueprintCallable)
    void OverrideSaveGameToSlot(const FString& SlotName, const FString& NewSlotName, ULocSaveGame* SaveGame, FSaveGameSavedEvent OnSaved);
    
    UFUNCTION(BlueprintCallable)
    void LoadSaveGame(const FString& SlotName, FSaveGameLoadedEvent OnSaveGameLoaded);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void LoadMMTCloudSaveGame(UObject* WorldContext, const FString& SaveGameName);
    
private:
    UFUNCTION(BlueprintCallable)
    void LoadMetaSaveGames();
    
    UFUNCTION(BlueprintCallable)
    void LoadGlobalSaveGame();
    
    UFUNCTION(BlueprintCallable)
    void InitializeGlobalSaveGame();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSaveGameCount();
    
private:
    UFUNCTION(BlueprintCallable)
    ULocMetaSaveGame* GetOldestAutosaveOrNew();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ULocMetaSaveGame* GetMetaForSaveSlot(const FString& SlotName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaxSaveGameCount() const;
    
    UFUNCTION(BlueprintCallable)
    TMap<FString, ULocMetaSaveGame*> GetListOfSaveGames();
    
    UFUNCTION(BlueprintCallable)
    TArray<FString> GetListOfSaveGameNamesSorted(bool bIncludeAutosaves);
    
    UFUNCTION(BlueprintCallable)
    bool GetLastLoadedSaveGameName(FString& SlotName);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static FString GetIncrementedSaveSlotName(UObject* WorldContext, const FString& Filename, const FString& Delimiter);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ULocGlobalSettingsSave* GetGlobalSettings() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ULocGlobalProfileSave* GetGlobalProfile() const;
    
private:
    UFUNCTION(BlueprintCallable)
    FString GetAutosaveNameForSlot(int32 Slot);
    
public:
    UFUNCTION(BlueprintCallable)
    TArray<ULocMetaSaveGame*> GetAutosaveMetas();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DoesSaveGameExist(const FString& SlotName) const;
    
    UFUNCTION(BlueprintCallable)
    void DeleteSaveGame(const FString& SlotName);
    
private:
    UFUNCTION(BlueprintCallable)
    ULocMetaSaveGame* CreateNewMetaSaveGame(const FString& SlotName, bool bIsAutosave);
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void CheckSaveGameModCompatibility(UObject* WorldContext, const FString& SlotName, FModdingCompatibilityEvent OnResult);
    
    UFUNCTION(BlueprintCallable)
    void Autosave(ULocSaveGame* SaveGame);
    
private:
    UFUNCTION(BlueprintCallable)
    void ApplyLoadedGlobalSettings();
    
    UFUNCTION(BlueprintCallable)
    void ApplyLoadedGlobalProfile();
    
};

