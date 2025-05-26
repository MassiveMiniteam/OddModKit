#pragma once
#include "CoreMinimal.h"
#include "NoiseGraphNodeMasterBase.h"
#include "NoiseGraphNodeMaster_GenericNoise.generated.h"

UCLASS(Blueprintable)
class LOC_API UNoiseGraphNodeMaster_GenericNoise : public UNoiseGraphNodeMasterBase {
    GENERATED_BODY()
public:
    UNoiseGraphNodeMaster_GenericNoise();

    virtual TArray<FString> GetInputs() const override
    {
        return { TEXT("A") };
    }

};

