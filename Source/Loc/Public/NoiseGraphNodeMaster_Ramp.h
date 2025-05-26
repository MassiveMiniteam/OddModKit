#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NoiseGraphNodeMaster_NoiseSpawnBase.h"
#include "NoiseGraphNodeMaster_Ramp.generated.h"

class ASimulationActor;
class UGridTileLandscapeLayer;

UCLASS(Blueprintable)
class LOC_API UNoiseGraphNodeMaster_Ramp : public UNoiseGraphNodeMaster_NoiseSpawnBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ASimulationActor> RampActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ASimulationActor> ConcaveRampActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ASimulationActor> ConvexRampActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* RampLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> Directions;
    
public:
    UNoiseGraphNodeMaster_Ramp();

    virtual TArray<FString> GetInputs() const override
    {
        return { TEXT("A") };
    }

};

