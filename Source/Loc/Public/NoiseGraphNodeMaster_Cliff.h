#pragma once
#include "CoreMinimal.h"
#include "NoiseGraphNodeMaster_NoiseSpawnBase.h"
#include "NoiseGraphNodeMaster_Cliff.generated.h"

class ASimulationActor;
class UGridTileLandscapeLayer;

UCLASS(Blueprintable)
class LOC_API UNoiseGraphNodeMaster_Cliff : public UNoiseGraphNodeMaster_NoiseSpawnBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<ASimulationActor>> SmallCliffActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<ASimulationActor>> HighCliffActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* LandscapeLayer;
    
public:
    UNoiseGraphNodeMaster_Cliff();

    virtual TArray<FString> GetInputs() const override
    {
        return { TEXT("A") };
    }
};

