#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LocPlayerId.h"
#include "SimulationCommandRecord.h"
#include "SimulationCommandFrameRecord.generated.h"

USTRUCT(BlueprintType)
struct FSimulationCommandFrameRecord {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocPlayerId OwnerId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSimulationCommandRecord> Commands;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> LastFrameHashes;
    
    LOCCORE_API FSimulationCommandFrameRecord();
};

