#pragma once
#include "CoreMinimal.h"
#include "NoiseGraphNodeMaster_NoiseSpawnObject.h"
#include "NoiseGraphNodeMaster_SpawnAroundTileType.generated.h"

class UGridTileLandscapeLayer;

UCLASS(Blueprintable)
class LOC_API UNoiseGraphNodeMaster_SpawnAroundTileType : public UNoiseGraphNodeMaster_NoiseSpawnObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* NextToLandscapeLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* AtLandscapeLayer;
    
public:
    UNoiseGraphNodeMaster_SpawnAroundTileType();
	
    virtual TArray<FString> GetInputs() const override
    {
        return { TEXT("A") };
    }

};

