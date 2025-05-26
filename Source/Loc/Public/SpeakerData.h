#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "VoicelineSensationData.h"
#include "SpeakerData.generated.h"

UCLASS(Blueprintable)
class LOC_API USpeakerData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FVoicelineSensationData> TagToVoicelineSensation;
    
    USpeakerData();

    UFUNCTION(BlueprintCallable)
    TMap<FGameplayTag, FVoicelineSensationData> SortAndReturn();
    
};

