#pragma once
#include "CoreMinimal.h"
#include "BiomeInstanceGeneratorSettings.h"
#include "NoiseGraphNode.h"
#include "NoiseGraphNodeMasterBase.generated.h"

class UNoiseModule;

UCLASS(Abstract, Blueprintable)
class LOC_API UNoiseGraphNodeMasterBase : public UNoiseGraphNode {
    GENERATED_BODY()
public:
	
    virtual TArray<FString> GetOutputs() const override
    {
        return {  };
    }

protected:
    UPROPERTY(Transient)
    UNoiseModule* NoiseModule = nullptr;
public:
	
    virtual UNoiseModule* GetNoiseModule(int32 InSeed) override
    {
        return GetNoiseAt(0, InSeed);
    }

    virtual void PreGenerate(FBiomeInstanceGeneratorSettings& GeneratorSettings)
    {
        NoiseModule = GetNoiseModule(GeneratorSettings.GeneratorSeed);
    }
	
    virtual void GenerateTile(FBiomeInstanceGeneratorSettings& GeneratorSettings, FIntPoint GridPosition)
    {
		
    }
	
    virtual FFixed64 GetHeightAt(UObject* WorldContext, int X, int Y, int Seed)
    {
        return NoiseModule->GetHeightAt(WorldContext, X, Y, Seed);
    }
};

