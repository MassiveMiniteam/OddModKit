#pragma once
#include "CoreMinimal.h"
#include "ElementState.generated.h"

class UElementDataAsset;

USTRUCT(BlueprintType)
struct FElementState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UElementDataAsset* Element;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Intensity;
    
    LOC_API FElementState();
};

