#pragma once
#include "CoreMinimal.h"
#include "Fixed64.h"
#include "NoiseGraphNodeMasterBase.h"
#include "NoiseGraphNodeMaster_NoiseSpawnBase.generated.h"

UCLASS(Abstract, Blueprintable)
class LOC_API UNoiseGraphNodeMaster_NoiseSpawnBase : public UNoiseGraphNodeMasterBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64 SpawnBetweenHeightMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64 SpawnBetweenHeightMax;
	
    virtual TArray<FString> GetInputs() const override
    {
        return { TEXT("A") };
    }
    
public:

	virtual void OnRenderPreviewTexturePixel(UNoiseModule* Noise, int X, int Y, int InSeed, FLinearColor& Color) override;

};

