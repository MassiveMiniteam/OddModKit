#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RampPositionRotationHeightSaveGameItem_New.generated.h"

USTRUCT(BlueprintType)
struct FRampPositionRotationHeightSaveGameItem_New {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint GridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint RotationAndHeight;
    
    LOC_API FRampPositionRotationHeightSaveGameItem_New();
};

