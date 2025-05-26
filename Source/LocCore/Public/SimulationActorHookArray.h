#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SimulationActorHookArray.generated.h"

class USimulationActorHook;

USTRUCT(BlueprintType)
struct FSimulationActorHookArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<USimulationActorHook>> Hooks;
    
    LOCCORE_API FSimulationActorHookArray();
};

