#pragma once
#include "CoreMinimal.h"
#include "Fixed64.h"
#include "NoiseGraphNodeMaster_NoiseSpawnBase.h"
#include "NoiseGraphNodeMaster_Lake.generated.h"

class UGridTileLandscapeLayer;
class ULocNoiseGraph;

UCLASS(Blueprintable)
class LOC_API UNoiseGraphNodeMaster_Lake : public UNoiseGraphNodeMaster_NoiseSpawnBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ULocNoiseGraph*> LakeDecoNoiseGraphs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64 MinDistanceToEdge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HeightOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* LandscapeLayer;
    
public:
    UNoiseGraphNodeMaster_Lake();
    
    virtual TArray<FString> GetInputs() const override
    {
        return { TEXT("A") };
    }

};

