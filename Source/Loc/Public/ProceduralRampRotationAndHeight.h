#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProceduralRampRotationAndHeight.generated.h"

USTRUCT(BlueprintType)
struct FProceduralRampRotationAndHeight : public FIntPoint {
    GENERATED_BODY()
public:
    LOC_API FProceduralRampRotationAndHeight();
};

