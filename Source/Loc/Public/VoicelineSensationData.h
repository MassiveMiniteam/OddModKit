#pragma once
#include "CoreMinimal.h"
#include "VoicelineSensationData.generated.h"

class USoundBase;
class UTexture2D;

USTRUCT(BlueprintType)
struct FVoicelineSensationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Headline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Image;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundBase> Voiceline;
    
    LOC_API FVoicelineSensationData();
};

