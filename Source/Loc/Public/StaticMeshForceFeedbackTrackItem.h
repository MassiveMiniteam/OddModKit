#pragma once
#include "CoreMinimal.h"
#include "StaticMeshForceFeedbackTrackItem.generated.h"

class UForceFeedbackAttenuation;
class UForceFeedbackEffect;
class USoundBase;

USTRUCT(BlueprintType)
struct FStaticMeshForceFeedbackTrackItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UForceFeedbackEffect> ForceFeedbackEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bFollow: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UForceFeedbackAttenuation> AttenuationSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bAdvancedHaptics: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundBase> AudioAsVibration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayInSeconds;
    
    LOC_API FStaticMeshForceFeedbackTrackItem();
};

