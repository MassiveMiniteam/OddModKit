#pragma once

#include "CoreMinimal.h"
#include "Fixed64.h"
#include "NoiseModuleSimplex.h"
#include "SimplexMath.h"
#include "NoiseModuleRidged.generated.h"

UCLASS(Blueprintable)
class MMTNOISE_API UNoiseModuleRidged : public UNoiseModuleSimplex
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FFixed64 SimplexMultiplier = 0.5f;
	
	virtual FFixed64 GetHeightAt(UObject* WorldContext, int X, int Y, int Seed) override
	{
		FFixed64 Height = Super::GetHeightAt(WorldContext, X, Y, Seed);
		Height = 1 - FMath::Abs(Height) * SimplexMultiplier;
		return Height;
	}
};
