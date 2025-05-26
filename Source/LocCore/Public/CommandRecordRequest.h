#pragma once
#include "CoreMinimal.h"
#include "CommandRecordRequest.generated.h"

USTRUCT(BlueprintType)
struct FCommandRecordRequest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> Bytes;
    
    LOCCORE_API FCommandRecordRequest();
};

