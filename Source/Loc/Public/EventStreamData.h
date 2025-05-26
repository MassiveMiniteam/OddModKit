#pragma once
#include "CoreMinimal.h"
#include "EventStreamData.generated.h"

USTRUCT(BlueprintType)
struct FEventStreamData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FString> EventStringData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, int32> EventIntData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, bool> EventBoolData;
    
    LOC_API FEventStreamData();
};

