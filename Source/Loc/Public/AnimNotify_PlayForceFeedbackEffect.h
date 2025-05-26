#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_PlayForceFeedbackEffect.generated.h"

class UForceFeedbackAttenuation;
class UForceFeedbackEffect;
class USoundBase;

UCLASS(Blueprintable, CollapseCategories, Config=Game)
class LOC_API UAnimNotify_PlayForceFeedbackEffect : public UAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UForceFeedbackEffect* ForceFeedbackEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UForceFeedbackAttenuation* AttenuationSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* AudioAsVibration;
    
    UAnimNotify_PlayForceFeedbackEffect();

};

