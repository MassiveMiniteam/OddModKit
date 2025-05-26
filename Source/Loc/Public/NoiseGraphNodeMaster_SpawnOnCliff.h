#pragma once
#include "CoreMinimal.h"
#include "NoiseGraphNodeMaster_NoiseSpawnObject.h"
#include "NoiseGraphNodeMaster_SpawnOnCliff.generated.h"

UCLASS(Blueprintable)
class LOC_API UNoiseGraphNodeMaster_SpawnOnCliff : public UNoiseGraphNodeMaster_NoiseSpawnObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinHeightDifference;
    
public:
    UNoiseGraphNodeMaster_SpawnOnCliff();

    virtual TArray<FString> GetInputs() const override
    {
        return { TEXT("A") };
    }

};

