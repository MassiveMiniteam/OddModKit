#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/SaveGame.h"
#include "DifficultySettings.h"
#include "SaveGameOptions.h"
#include "LocCoreSaveGame.generated.h"

class UObject;

UCLASS(Blueprintable)
class LOCCORE_API ULocCoreSaveGame : public USaveGame {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FSaveGameOptions Options;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FDifficultySettings DifficultySettingsOnNewGame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString SaveSlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString SeedString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGuid UniqueID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OverrideSeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDateTime LocalLoadTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<uint8> CompressedData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<uint8> TmpAsyncCompressedData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<uint8> TmpAsyncUncompressedData;
    
    ULocCoreSaveGame();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnLoadSaveGameFinished();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCollectSaveGameFinished();
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void LoadSaveGame(const UObject* WorldContext, bool bIsForNetworking);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsEmpty() const;
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void CollectSaveGame(const UObject* WorldContext, bool bIsForNetworking);
    
};

