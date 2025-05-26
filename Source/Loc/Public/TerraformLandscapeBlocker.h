#pragma once
#include "CoreMinimal.h"
#include "TerraformLandscapeBlocker.generated.h"

class UGridTileLandscapeLayer;

USTRUCT(BlueprintType)
struct FTerraformLandscapeBlocker {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UGridTileLandscapeLayer> LandscapeLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Range;
    
    LOC_API FTerraformLandscapeBlocker();
};

