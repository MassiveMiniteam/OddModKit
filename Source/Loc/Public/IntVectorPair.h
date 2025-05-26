#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IntVectorPair.generated.h"

USTRUCT(BlueprintType)
struct FIntVectorPair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector A;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector B;
    
    LOC_API FIntVectorPair();
};

