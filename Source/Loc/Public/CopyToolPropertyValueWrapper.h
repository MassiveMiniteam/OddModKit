#pragma once
#include "CoreMinimal.h"
#include "CopyToolValueMapping.h"
#include "CopyToolPropertyValueWrapper.generated.h"

class ASimulationPlayer;

USTRUCT(BlueprintType)
struct FCopyToolPropertyValueWrapper {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString ComponentName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FCopyToolValueMapping> Data;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* ExecutingSimulationPlayer;
    
    LOC_API FCopyToolPropertyValueWrapper();
};

