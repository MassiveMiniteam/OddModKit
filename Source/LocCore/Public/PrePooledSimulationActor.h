#pragma once
#include "CoreMinimal.h"
#include "PrePooledSimulationActor.generated.h"

class ASimulationActor;

USTRUCT(BlueprintType)
struct FPrePooledSimulationActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ASimulationActor> Class;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PoolAmount;
    
    LOCCORE_API FPrePooledSimulationActor();
};

