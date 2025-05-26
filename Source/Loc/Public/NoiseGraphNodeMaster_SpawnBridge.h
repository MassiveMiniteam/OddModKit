#pragma once
#include "CoreMinimal.h"
#include "NoiseGraphNodeMaster_NoiseSpawnObject.h"
#include "NoiseGraphNodeMaster_SpawnBridge.generated.h"

class UGridTileLandscapeLayer;

UCLASS(Blueprintable)
class LOC_API UNoiseGraphNodeMaster_SpawnBridge : public UNoiseGraphNodeMaster_NoiseSpawnObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* LandscapeLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinimumHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinimumDeep;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaximumHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BridgeDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinimumWaterTiles;
    
public:
    UNoiseGraphNodeMaster_SpawnBridge();

    virtual TArray<FString> GetInputs() const override
    {
        return { TEXT("A") };
    }

};

