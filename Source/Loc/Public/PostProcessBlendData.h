#pragma once
#include "CoreMinimal.h"
#include "PostProcessBlendData.generated.h"

class ALocPostProcessingVolume;

USTRUCT(BlueprintType)
struct FPostProcessBlendData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ALocPostProcessingVolume* PostProcessVolume;
    
    LOC_API FPostProcessBlendData();
};

