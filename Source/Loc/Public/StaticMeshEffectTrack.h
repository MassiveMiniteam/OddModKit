#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "StaticMeshAudioEffectTrackItem.h"
#include "StaticMeshForceFeedbackTrackItem.h"
#include "StaticMeshVisualEffectTrackItem.h"
#include "StaticMeshEffectTrack.generated.h"

UCLASS(Blueprintable)
class LOC_API UStaticMeshEffectTrack : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStaticMeshAudioEffectTrackItem> AudioItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStaticMeshVisualEffectTrackItem> VisualItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStaticMeshForceFeedbackTrackItem> ForceFeedbackItems;
    
    UStaticMeshEffectTrack();

};

