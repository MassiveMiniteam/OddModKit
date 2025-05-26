#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NoiseGraphNodeMaster_NoiseSpawnBase.h"
#include "NoiseGraphNodeMaster_NoiseGroundLayer.generated.h"

class UGridTileGroundLayer;

UCLASS(Blueprintable)
class LOC_API UNoiseGraphNodeMaster_NoiseGroundLayer : public UNoiseGraphNodeMaster_NoiseSpawnBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileGroundLayer* Layer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint HeightRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowNexToCliffs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowPlacingOnExistingCustomGroundLayer;
    
    UNoiseGraphNodeMaster_NoiseGroundLayer();

};

