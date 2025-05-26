#pragma once
#include "CoreMinimal.h"
#include "LocPlayerId.h"
#include "SimulationCommandRecord.h"
#include "SimulationCommandFrameOwnerRecord.generated.h"

USTRUCT(BlueprintType)
struct FSimulationCommandFrameOwnerRecord {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocPlayerId OwnerId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimulationCommandRecord CommandRecord;
    
    LOCCORE_API FSimulationCommandFrameOwnerRecord();
};

