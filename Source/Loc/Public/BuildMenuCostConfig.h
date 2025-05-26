#pragma once
#include "CoreMinimal.h"
#include "BuildMenuCostConfig.generated.h"

class UConstructableConfig;

USTRUCT(BlueprintType)
struct FBuildMenuCostConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConstructableConfig* ConstructableConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Amount;
    
    LOC_API FBuildMenuCostConfig();
};

