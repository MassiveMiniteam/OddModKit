#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/GameStateBase.h"
#include "PlayerPUIDPair.h"
#include "Templates/SubclassOf.h"
#include "LocCoreGameState.generated.h"

class ANetworkManager;
class APlayerState;
class ASimulationManager;
class ASimulationScheduler;
class ULocCoreSaveGame;

UCLASS(Blueprintable)
class LOCCORE_API ALocCoreGameState : public AGameStateBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnSimulation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnScheduler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnNetworkManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASimulationManager* SimulationManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASimulationScheduler* SimulationScheduler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ANetworkManager> NetworkManager;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ShowLoadingScreen, meta=(AllowPrivateAccess=true))
    bool bShowLoadingScreen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid SavegameSessionId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ULocCoreSaveGame> SaveGameClass;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<FPlayerPUIDPair> PlayerPUIDsArray;
    
public:
    ALocCoreGameState(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUpdatePlayerPUID(FPlayerPUIDPair PlayerPUIDPair);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_ShowLoadingScreen();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASimulationScheduler* GetSimulationScheduler() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASimulationManager* GetSimulationManager() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetPlayerPUID(APlayerState* PlayerState) const;
    
    UFUNCTION(BlueprintCallable)
    ANetworkManager* GetNetworkManager();
    
};

