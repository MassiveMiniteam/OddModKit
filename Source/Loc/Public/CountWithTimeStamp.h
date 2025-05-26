#pragma once
#include "CoreMinimal.h"
#include "Fixed64.h"
#include "CountWithTimeStamp.generated.h"

USTRUCT(BlueprintType)
struct FCountWithTimeStamp {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Count;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed64 Timestamp;
    
    LOC_API FCountWithTimeStamp();
};

