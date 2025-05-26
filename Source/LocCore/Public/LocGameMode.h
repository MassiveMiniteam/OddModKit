#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/OnlineReplStructs.h"
#include "LoginPlayerTask.h"
#include "LogoutEventDelegate.h"
#include "NetworkSavGameEventDelegate.h"
#include "LocGameMode.generated.h"

class AController;
class ALocCorePlayerController;
class APlayerController;
class ASimulationManager;
class ULocCoreSaveGame;

UCLASS(Blueprintable, NonTransient)
class LOCCORE_API ALocGameMode : public AGameModeBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBlockIncomingJoinRequests;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLogoutEvent OnPlayerLogout;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNetworkSavGameEvent OnNetworkSaveGameCreated;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AController*> WaitingForPlayersJoinInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AController*> WaitingForPlayersToBeKicked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLoginPlayerTask> LoginTasks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FrameToSerializeState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsWaitingForPlayerLoad;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 LastLogoutFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULocCoreSaveGame* SerializedStateToJoin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInited;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ALocCorePlayerController*, bool> PlayersFinishedStreamingSavegame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FUniqueNetIdRepl, int32> PreLoginLocalPlayerIds;
    
public:
    ALocGameMode(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void PostLoginWaitForCharacterSpawn(APlayerController* NewPlayer);
    
    UFUNCTION(BlueprintCallable)
    void OnPostSimulationTick(ASimulationManager* SimulationManager);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPostInitializeComponents();
    
    UFUNCTION(BlueprintCallable)
    void HandlePlayerLogin(APlayerController* NewPlayer);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetIsSessionCreationAllowed();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetIsPresenceJoinAllowed();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    ULocCoreSaveGame* CreateEditorSavegame();
    
};

