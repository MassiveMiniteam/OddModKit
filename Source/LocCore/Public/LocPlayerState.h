#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "LocPlayerId.h"
#include "SimulationCommandSyncRecord.h"
#include "LocPlayerState.generated.h"

UCLASS(Blueprintable)
class LOCCORE_API ALocPlayerState : public APlayerState {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FLocPlayerId LocPlayerId;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bIsSimulationReady;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bIsLoggingIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSimulationCommandSyncRecord> DelayedSyncRecords;
    
    ALocPlayerState(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetLocPlayerId(FLocPlayerId ID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLocPlayerId GetLocPlayerId() const;
    
};

