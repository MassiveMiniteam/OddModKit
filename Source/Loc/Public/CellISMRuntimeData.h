#pragma once
#include "CoreMinimal.h"
#include "CellISMRuntimeData.generated.h"

USTRUCT(BlueprintType)
struct FCellISMRuntimeData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ConfigValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ISMIndex;
    
    LOC_API FCellISMRuntimeData();
};

