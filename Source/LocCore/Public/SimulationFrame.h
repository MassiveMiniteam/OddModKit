#pragma once
#include "CoreMinimal.h"
#include "LocPlayerId.h"
#include "SimulationPlayerFrame.h"
#include "SimulationFrame.generated.h"

USTRUCT(BlueprintType)
struct FSimulationFrame {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FLocPlayerId, FSimulationPlayerFrame> Frames;
    
    LOCCORE_API FSimulationFrame();
};

