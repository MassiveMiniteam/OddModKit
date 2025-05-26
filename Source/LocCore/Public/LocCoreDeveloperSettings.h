#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GameplayTagContainer.h"
#include "EMyUserPrivileges.h"
#include "FixedInterval.h"
#include "PrePooledSimulationActor.h"
#include "Templates/SubclassOf.h"
#include "LocCoreDeveloperSettings.generated.h"

class UDifficultySettingsPreset;
class UUserWidget;

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class LOCCORE_API ULocCoreDeveloperSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> MessageUserWidget;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseGlobalInvalidation;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText UIDescription_VersionMismatch;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description_GenericError;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title_GenericError;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText UIDescription_ConnectionLoss;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText UIDescription_TimeOut;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText UIDescription_Desync;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title_RoomCodeError;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title_SessionCreationFail;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText SessionCreationFail;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title_ErrorHostInIntro;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title_Host;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title_SendingFailed;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText UIDescription_HostClosedSession;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText UIDescription_Kick_ModsIncompatible;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText UIDescription_Crash_Mods;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText UITitle_ErrorKicked;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title_None;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPrePooledSimulationActor> PrePooledSimulationActors;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UDifficultySettingsPreset> DefaultDifficultyPreset_Development;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UDifficultySettingsPreset> DefaultDifficultyPreset;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FFixedInterval> DifficultySettingsWithAchievementCompatibleRange;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EMyUserPrivileges> UserPrivileges;
    
    ULocCoreDeveloperSettings();

};

