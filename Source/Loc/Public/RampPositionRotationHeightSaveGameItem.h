#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RampPositionRotationHeightSaveGameItem.generated.h"

USTRUCT(BlueprintType)
struct FRampPositionRotationHeightSaveGameItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint GridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint RotationAndHeight;
    
    LOC_API FRampPositionRotationHeightSaveGameItem();
};

