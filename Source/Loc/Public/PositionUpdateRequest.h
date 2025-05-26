#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PositionUpdateRequest.generated.h"

USTRUCT(BlueprintType)
struct FPositionUpdateRequest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint GridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsHeightChange;
    
    LOC_API FPositionUpdateRequest();
};

