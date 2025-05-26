#pragma once
#include "CoreMinimal.h"
#include "LocPlayerId.h"
#include "SimulationPlayerFrame.generated.h"

class USimulationCommand;

USTRUCT(BlueprintType)
struct FSimulationPlayerFrame {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocPlayerId OwnerId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USimulationCommand*> Commands;
    
    LOCCORE_API FSimulationPlayerFrame();
};

