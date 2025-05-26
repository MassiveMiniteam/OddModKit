#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "LocActor.h"
#include "LocPlayerId.h"
#include "PlayerNetworkEventDelegate.h"
#include "SimulationCommandRunEventDelegate.h"
#include "SimulationFrame.h"
#include "SimulationHashRecord.h"
#include "SimulationSchedulerConditionalDelegate.h"
#include "SimulationTickRegistration.h"
#include "SimulationScheduler.generated.h"

class USimulationCommand;

UCLASS(Blueprintable)
class LOCCORE_API ASimulationScheduler : public ALocActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<USimulationCommand*, uint32> CurrentLocalSimulationCommands;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AdjustLookAheadLocalTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentLookaheadMisses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumPlayers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLocPlayerId> SortedPlayerIds;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<uint32, uint32> ServerFrameHashHistory;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<uint32, uint32> QueuedFrameHashHistory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USimulationCommand*> PredictedCommands;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerNetworkEvent OnNewPlayerJoined;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerNetworkEvent OnOldPlayerJoined;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerNetworkEvent OnPlayerLeft;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerNetworkEvent OnLocalPlayerFinishedSetup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocPlayerId HostPlayerId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSimulationTickRegistration> RegisteredTickFunctions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimulationSchedulerConditional CanTickSimulation;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<uint32, FSimulationHashRecord> LocalFrameHashHistory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimulationCommandRunEvent OnRunSimulationCommand;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<uint32, FSimulationFrame> NextFrames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed TimeScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsDesynced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckForDesync;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 IgnoreDesyncUntilFrame;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 SendOutCommandsUntilFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> CommandRingHistory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> NameRingHistory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimulationHashRecord CurrentFrameSimulationHashRecord;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimulationHashRecord LastFrameSimulationHashRecord;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CommandRecorderFileName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRecordCommandsToFile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasRecordedInitialSaveGame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsPlayingBackRecording;
    
    ASimulationScheduler(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateTimeStepEnabledStateFromGlobalSettings();
    
    UFUNCTION(BlueprintCallable)
    void SetNumPlayers(int32 NewPlayerNum);
    
    UFUNCTION(BlueprintCallable)
    void SetFixedUpdateDisabled(bool bDisabled);
    
    UFUNCTION(BlueprintCallable)
    void LoadPrespawnedSimulationActors();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FLocPlayerId> GetSortedPlayerIds();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumPlayers() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetFrameNumberAsInt() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetFrameLookahead() const;
    
    UFUNCTION(BlueprintCallable)
    FString DiffHashRecords(FSimulationHashRecord& ServerHash, FSimulationHashRecord& ClientHash, FString& log);
    
    UFUNCTION(BlueprintCallable)
    void ClearSimulation();
    
};

