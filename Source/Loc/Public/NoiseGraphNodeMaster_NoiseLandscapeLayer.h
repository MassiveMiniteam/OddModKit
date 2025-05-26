#pragma once
#include "CoreMinimal.h"
#include "NoiseGraphNodeMaster_NoiseSpawnBase.h"
#include "NoiseGraphNodeMaster_NoiseLandscapeLayer.generated.h"

class UGridTileLandscapeLayer;

UCLASS(Blueprintable)
class LOC_API UNoiseGraphNodeMaster_NoiseLandscapeLayer : public UNoiseGraphNodeMaster_NoiseSpawnBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* Layer;
    
    UNoiseGraphNodeMaster_NoiseLandscapeLayer();

};

