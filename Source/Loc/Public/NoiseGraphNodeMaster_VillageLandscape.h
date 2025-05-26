#pragma once
#include "CoreMinimal.h"
#include "NoiseGraphNodeMasterBase.h"
#include "NoiseGraphNodeMaster_VillageLandscape.generated.h"

class UVillageLandscapeData;

UCLASS(Blueprintable)
class LOC_API UNoiseGraphNodeMaster_VillageLandscape : public UNoiseGraphNodeMasterBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UVillageLandscapeData* VillageLandscapeData;
    
public:
    UNoiseGraphNodeMaster_VillageLandscape();

    virtual TArray<FString> GetInputs() const override
    {
        return { TEXT("A") };
    }

};

