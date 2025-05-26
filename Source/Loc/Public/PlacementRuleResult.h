#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlacementRuleResult.generated.h"

class UGridPlacementRuleConfig;

USTRUCT(BlueprintType)
struct FPlacementRuleResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> ValidTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> InvalidTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> ValidExternalTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> InvalidExternalTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridPlacementRuleConfig* PlacementRuleConfig;
    
    LOC_API FPlacementRuleResult();
};

