#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "ItemStack.h"
#include "ProcessRateOutputConfig.generated.h"

USTRUCT(BlueprintType)
struct FProcessRateOutputConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed ProcessRateModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemStack OutputItem;
    
    LOC_API FProcessRateOutputConfig();
};

