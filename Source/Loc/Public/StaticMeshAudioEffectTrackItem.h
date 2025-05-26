#pragma once
#include "CoreMinimal.h"
#include "StaticMeshAudioEffectTrackItem.generated.h"

class USoundBase;

USTRUCT(BlueprintType)
struct FStaticMeshAudioEffectTrackItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundBase> SoundCue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayInSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartStopOnce;
    
    LOC_API FStaticMeshAudioEffectTrackItem();
};

