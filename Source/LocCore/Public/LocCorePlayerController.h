#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LocPlayerId.h"
#include "SimulationCommandFrameRecord.h"
#include "SimulationCommandSyncRecord.h"
#include "SimulationHashRecord.h"
#include "SimulationHashRecordFragmentContainer.h"
#include "LocCorePlayerController.generated.h"

class ASimulationManager;

UCLASS(Blueprintable)
class LOCCORE_API ALocCorePlayerController : public APlayerController {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsStreamingToClient;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsStreamingSaveGame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SaveGameTotalFragmentCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SaveGameCurrentFragmentCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSimulationHashRecordFragmentContainer> DesyncReportToStreamToClient;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BytesPerFragment;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 LastPingTime;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 CurrentPingDelay;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Ping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSyncCommands;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSimulationCommandSyncRecord> CommandsToSync;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TargetNumPlayers;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> TemporarySerializedSaveGame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimulationHashRecordFragmentContainer DesyncServerHashReport;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 DesyncServerHashFrameNumber;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 DesyncTargetHashFrameNumber;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DesyncSendOutServerHashFrameNumber;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint32> CommandsToBeAcked;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 SyncIndexCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasGameStarted;
    
public:
    ALocCorePlayerController(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StreamSavegameOnGameStarted(int32 NumPlayers, const TArray<uint8>& SerializedGameData);
    
    UFUNCTION(BlueprintCallable)
    void StreamDesyncReportToClient(FSimulationHashRecord& Record, int32 Frame);
    
    UFUNCTION(BlueprintCallable)
    void StartNetworkGame();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSetPlayerIsReadyToSimulate();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSetPlayerIsReady();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerRequestSerializedSimulation(int32 Frame);
    
    UFUNCTION(Server, Unreliable)
    void ServerPing(double PingTime);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerNotifyFinishedReceivingSavegame();
    
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void ServerDistributeCommands(int32 PlayerNum, const TArray<uint8>& SyncRecords);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerAnswerPlayerUniqueId(FLocPlayerId NetId);
    
    UFUNCTION(Reliable, Server)
    void ServerAckCommands(bool bIsAckAck, const TArray<uint32>& SyncRecords);
    
    UFUNCTION(BlueprintCallable)
    void OnPreSimulationTickCheckDesync(ASimulationManager* SimulationManager);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnGameStarted();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocSimulateNetworkFailure();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocSimulateDesync();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetStreamingSaveGameFragmentProgress() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetStreamingSaveGameFragmentNum() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsStreamingSaveGame() const;
    
    UFUNCTION(BlueprintCallable)
    void GatherDesyncReportAndSendToClient();
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientUpdateSaveGameStreamInfo(bool bIsStreaming, int32 TotalFragmentCount);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientRequestPlayerUniqueId();
    
    UFUNCTION(Client, Reliable)
    void ClientReceiveSerializedSimulation(uint32 FrameNumber, const FSimulationHashRecordFragmentContainer& ServerHashes);
    
    UFUNCTION(Client, Unreliable)
    void ClientPong(double PingTime);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientOnGameStartedStreamFinished(int32 TargetPlayerNum);
    
    UFUNCTION(BlueprintCallable, Client, Unreliable)
    void ClientDistributeCommands(const TArray<uint8>& SyncRecords);
    
    UFUNCTION(Client, Reliable)
    void ClientAckCommands(bool bIsAckAck, const TArray<uint32>& SyncRecords);
    
    UFUNCTION()
    void CheckDesyncReport(uint32 FrameNumber);
    
    UFUNCTION(BlueprintCallable)
    void AddSyncSimulationCommand(const FSimulationCommandFrameRecord& Record);
    
};

