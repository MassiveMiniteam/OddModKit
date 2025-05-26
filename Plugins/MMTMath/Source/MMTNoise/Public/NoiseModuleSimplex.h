#pragma once

#include "CoreMinimal.h"
#include "Fixed64.h"
#include "SimplexMath.h"
#include "NoiseModuleSimplex.generated.h"

UCLASS(Blueprintable)
class MMTNOISE_API UNoiseModuleSimplex : public UNoiseModule
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FFixed64 Frequency = 0.019989f;
	UPROPERTY(EditAnywhere)
	FFixed64 Amplitude = 1.0f;
	UPROPERTY(EditAnywhere)
	FFixed64 Lacunarity = 2.0f;
	UPROPERTY(EditAnywhere)
	FFixed64 Persistence = 0.5f;
	UPROPERTY(EditAnywhere)
	int Octaves = 3;
	UPROPERTY(EditAnywhere)
	FFixed64 ResolutionMultiplier = FFixed64(0.1);
	
	virtual FFixed64 GetHeightAt(UObject* WorldContext, int X, int Y, int Seed) override
	{
		FFixed64 output = 0.f;
		FFixed64 Freq = Frequency;
		FFixed64 Denom = 0;
		FFixed64 Ampl = Amplitude;

		for (size_t i = 0; i < Octaves; i++)
		{
			int X1 = static_cast<int>(FFixed64::Round(X / ResolutionMultiplier));
			int Y1 = static_cast<int>(FFixed64::Round(Y / ResolutionMultiplier));
			output = output + Ampl * SimplexNoise(X1 * static_cast<float>(ResolutionMultiplier * Freq), Y1 * static_cast<float>(ResolutionMultiplier * Freq), Seed);
			Denom = Denom + Ampl;
		
			Freq = Freq * Lacunarity;
			Ampl = Ampl * Persistence;
		}

		FFixed64 Height = output / Denom;
		return Height;
	}
};
