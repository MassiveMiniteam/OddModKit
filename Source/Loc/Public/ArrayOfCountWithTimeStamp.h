#pragma once
#include "CoreMinimal.h"
#include "CountWithTimeStamp.h"
#include "ArrayOfCountWithTimeStamp.generated.h"

USTRUCT(BlueprintType)
struct FArrayOfCountWithTimeStamp {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FCountWithTimeStamp> Data;
    
    LOC_API FArrayOfCountWithTimeStamp();
};

