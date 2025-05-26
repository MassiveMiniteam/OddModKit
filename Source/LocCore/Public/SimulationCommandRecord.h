#pragma once
#include "CoreMinimal.h"
#include "SimulationCommandRecord.generated.h"

USTRUCT(BlueprintType)
struct FSimulationCommandRecord {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Version;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* Class;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 FrameNumber;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> Data;
    
    LOCCORE_API FSimulationCommandRecord();
};

