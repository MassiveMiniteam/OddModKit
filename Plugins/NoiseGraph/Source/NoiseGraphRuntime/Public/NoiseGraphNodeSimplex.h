#pragma once

#include "CoreMinimal.h"
#include "NoiseModule.h"
#include "Templates/SubclassOf.h"
#include "NoiseGraphNode.h"
#include "NoiseModuleSimplex.h"
#include "NoiseGraphNodeSimplex.generated.h"

UCLASS(Blueprintable)
class NOISEGRAPHRUNTIME_API UNoiseGraphNodeSimplex : public UNoiseGraphNodeNoiseBase
{
	GENERATED_BODY()

protected:
	/** The Frequency determines the size/scale of the Noise features or in other words think of it like the "Texture Repeat" of the Noise.  */
	UPROPERTY(EditAnywhere)
	FFixed64 Frequency = 0.019989f;
	/** The height and steepness of the noise */
	UPROPERTY(EditAnywhere)
	FFixed64 Amplitude = 1.0f;
	/** Frequency multiplier per octave. with each octave the frequency of the next goes higher by this multiplier (or less if < 1)  */
	UPROPERTY(EditAnywhere)
	FFixed64 Lacunarity = 2.0f;
	/** Amplitude multiplier per octave. with each octave the amplitude of the next is multiplied by this  */
	UPROPERTY(EditAnywhere)
	FFixed64 Persistence = 0.5f;
	/** How many noises are combined and blend together */
	UPROPERTY(EditAnywhere)
	int Octaves = 3;
	/** If > 1 -> snaps the X and Y coordinates in a grid based on this value */
	UPROPERTY(EditAnywhere)
	FFixed64 ResolutionMultiplier = FFixed64(0.1);
	
	virtual TSubclassOf<UNoiseModule> GetNoiseModuleClass() const override
	{
		return UNoiseModuleSimplex::StaticClass();
	}
	
	virtual UNoiseModule* GetNoiseModule(int32 InSeed) override
	{
		UNoiseModuleSimplex* Noise = Cast<UNoiseModuleSimplex>(Super::GetNoiseModule(InSeed));
		Noise->Frequency = Frequency;
		Noise->Amplitude = Amplitude;
		Noise->Lacunarity = Lacunarity;
		Noise->Persistence = Persistence;
		Noise->Octaves = Octaves;
		Noise->ResolutionMultiplier = ResolutionMultiplier;
		return Noise;
	}
	
};
