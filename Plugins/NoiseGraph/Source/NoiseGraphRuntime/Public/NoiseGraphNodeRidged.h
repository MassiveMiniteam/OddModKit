#pragma once

#include "CoreMinimal.h"
#include "NoiseModule.h"
#include "Templates/SubclassOf.h"
#include "NoiseGraphNode.h"
#include "NoiseModuleSimplex.h"
#include "NoiseGraphNodeSimplex.h"
#include "NoiseModuleRidged.h"
#include "NoiseGraphNodeRidged.generated.h"

UCLASS(Blueprintable)
class NOISEGRAPHRUNTIME_API UNoiseGraphNodeRidged : public UNoiseGraphNodeSimplex
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	FFixed64 SimplexMultiplier = 0.5f;
	
	virtual TSubclassOf<UNoiseModule> GetNoiseModuleClass() const override
	{
		return UNoiseModuleRidged::StaticClass();
	}
	
	virtual UNoiseModule* GetNoiseModule(int32 InSeed) override
	{
		UNoiseModuleRidged* Noise = Cast<UNoiseModuleRidged>(Super::GetNoiseModule(InSeed));
		Noise->SimplexMultiplier = SimplexMultiplier;
		Noise->Frequency = Frequency;
		Noise->Amplitude = Amplitude;
		Noise->Lacunarity = Lacunarity;
		Noise->Persistence = Persistence;
		Noise->Octaves = Octaves;
		Noise->ResolutionMultiplier = ResolutionMultiplier;
		return Noise;
	}
	
};
