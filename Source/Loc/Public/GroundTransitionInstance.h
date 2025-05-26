#pragma once
#include "CoreMinimal.h"
#include "GroundTransitionInstance.generated.h"

class UGridTileGroundLayer;

USTRUCT(BlueprintType)
struct FGroundTransitionInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileGroundLayer* GroundLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Index;
    
    LOC_API FGroundTransitionInstance();
};

