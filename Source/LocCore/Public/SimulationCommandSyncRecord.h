#pragma once
#include "CoreMinimal.h"
#include "SimulationCommandFrameRecord.h"
#include "SimulationCommandSyncRecord.generated.h"

USTRUCT(BlueprintType)
struct FSimulationCommandSyncRecord {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 SyncIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimulationCommandFrameRecord CommandFrame;
    
    LOCCORE_API FSimulationCommandSyncRecord();
};

