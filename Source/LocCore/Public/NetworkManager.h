#pragma once
#include "CoreMinimal.h"
#include "LocActor.h"
#include "SimulationCommandFrameRecord.h"
#include "NetworkManager.generated.h"

UCLASS(Blueprintable)
class LOCCORE_API ANetworkManager : public ALocActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSimulationCommandFrameRecord> QueuedCommandFrameRecords;
    
    ANetworkManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastHandlePlayerJoin(bool bReenableSendOut);
    
};

