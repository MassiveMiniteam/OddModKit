#pragma once
#include "CoreMinimal.h"
#include "SimulationHashRecordItem.h"
#include "SimulationHashRecordFragmentContainer.generated.h"

USTRUCT(BlueprintType)
struct FSimulationHashRecordFragmentContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSimulationHashRecordItem> HashMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HashMapCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SentHashMapCount;
    
    LOCCORE_API FSimulationHashRecordFragmentContainer();
};

