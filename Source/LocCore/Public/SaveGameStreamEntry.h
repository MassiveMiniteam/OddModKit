#pragma once
#include "CoreMinimal.h"
#include "SaveGameStreamEntry.generated.h"

USTRUCT(BlueprintType)
struct FSaveGameStreamEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Index;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> Bytes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Offset;
    
    LOCCORE_API FSaveGameStreamEntry();
};

