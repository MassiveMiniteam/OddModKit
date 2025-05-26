#pragma once

#include "CoreMinimal.h"
#include "Fixed64.h"
#include "NoiseModule.h"
#include "NoiseModules.generated.h"

UCLASS(Blueprintable)
class MMTNOISE_API UNoiseModuleAdd : public UNoiseModule
{
	GENERATED_BODY()

public:
	virtual int GetSourceModuleCount() const override { return 2; }

	virtual FFixed64 GetHeightAt(UObject* WorldContext, int X, int Y, int Seed) override
	{
		return SourceModules[0]->GetHeightAt(WorldContext, X, Y, Seed) + SourceModules[1]->GetHeightAt(WorldContext, X, Y, Seed);
	}
};

UCLASS(Blueprintable)
class MMTNOISE_API UNoiseModuleMultiply : public UNoiseModule
{
	GENERATED_BODY()

public:
	virtual int GetSourceModuleCount() const override { return 2; }

	virtual FFixed64 GetHeightAt(UObject* WorldContext, int X, int Y, int Seed) override
	{
		return SourceModules[0]->GetHeightAt(WorldContext, X, Y, Seed) * SourceModules[1]->GetHeightAt(WorldContext, X, Y, Seed);
	}
};

UCLASS(Blueprintable)
class MMTNOISE_API UNoiseModuleSubtract : public UNoiseModule
{
	GENERATED_BODY()

public:
	virtual int GetSourceModuleCount() const override { return 2; }

	virtual FFixed64 GetHeightAt(UObject* WorldContext, int X, int Y, int Seed) override
	{
		return SourceModules[0]->GetHeightAt(WorldContext, X, Y, Seed) - SourceModules[1]->GetHeightAt(WorldContext, X, Y, Seed);
	}
};

UCLASS(Blueprintable)
class MMTNOISE_API UNoiseModuleAbs : public UNoiseModule
{
	GENERATED_BODY()

public:
	virtual int GetSourceModuleCount() const override { return 1; }

	virtual FFixed64 GetHeightAt(UObject* WorldContext, int X, int Y, int Seed) override
	{
		return FMath::Abs(SourceModules[0]->GetHeightAt(WorldContext, X, Y, Seed));
	}
};

UCLASS(Blueprintable)
class MMTNOISE_API UNoiseModuleMin : public UNoiseModule
{
	GENERATED_BODY()

public:
	virtual int GetSourceModuleCount() const override { return 2; }

	virtual FFixed64 GetHeightAt(UObject* WorldContext, int X, int Y, int Seed) override
	{
		return FMath::Min(SourceModules[0]->GetHeightAt(WorldContext, X, Y, Seed), SourceModules[1]->GetHeightAt(WorldContext, X, Y, Seed));
	}
};

UCLASS(Blueprintable)
class MMTNOISE_API UNoiseModuleMax : public UNoiseModule
{
	GENERATED_BODY()

public:
	virtual int GetSourceModuleCount() const override { return 2; }

	virtual FFixed64 GetHeightAt(UObject* WorldContext, int X, int Y, int Seed) override
	{
		return FMath::Max(SourceModules[0]->GetHeightAt(WorldContext, X, Y, Seed), SourceModules[1]->GetHeightAt(WorldContext, X, Y, Seed));
	}
};

UCLASS(Blueprintable)
class MMTNOISE_API UNoiseModuleConst : public UNoiseModule
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFixed64 Const;

	virtual int GetSourceModuleCount() const override { return 0; }

	virtual FFixed64 GetHeightAt(UObject* WorldContext, int X, int Y, int Seed) override
	{
		return Const;
	}
};

UCLASS(Blueprintable)
class MMTNOISE_API UNoiseModuleClamp : public UNoiseModule
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFixed64 Min;
	UPROPERTY()
	FFixed64 Max;

	virtual int GetSourceModuleCount() const override { return 1; }

	virtual FFixed64 GetHeightAt(UObject* WorldContext, int X, int Y, int Seed) override
	{
		return FMath::Clamp(SourceModules[0]->GetHeightAt(WorldContext, X, Y, Seed), Min, Max);
	}
};

UCLASS(Blueprintable)
class MMTNOISE_API UNoiseModulePower : public UNoiseModule
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int Power;

	virtual int GetSourceModuleCount() const override { return 1; }

	virtual FFixed64 GetHeightAt(UObject* WorldContext, int X, int Y, int Seed) override
	{
		FFixed64 Value = SourceModules[0]->GetHeightAt(WorldContext, X, Y, Seed);
		FFixed64 Result = Value;
		for (int i = 0; i < Power; i++)
		{
			Result = Result * Value;
		}
		return Result;
	}
};

UCLASS(Blueprintable)
class MMTNOISE_API UNoiseModuleRemap : public UNoiseModule
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFixed64 FromLow;
	UPROPERTY()
	FFixed64 FromHigh;

	UPROPERTY()
	FFixed64 ToLow;
	UPROPERTY()
	FFixed64 ToHigh;

	virtual int GetSourceModuleCount() const override { return 1; }

	virtual FFixed64 GetHeightAt(UObject* WorldContext, int X, int Y, int Seed) override
	{
		FFixed64 Value = SourceModules[0]->GetHeightAt(WorldContext, X, Y, Seed);
		Value = ToLow + (Value - FromLow) * (ToHigh - ToLow) / (FromHigh - FromLow);
		return Value;
	}
};

UCLASS(Blueprintable)
class MMTNOISE_API UNoiseModuleMask : public UNoiseModule
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFixed64 From;
	UPROPERTY()
	FFixed64 To;

	virtual int GetSourceModuleCount() const override { return 1; }

	virtual FFixed64 GetHeightAt(UObject* WorldContext, int X, int Y, int Seed) override
	{
		FFixed64 Value = SourceModules[0]->GetHeightAt(WorldContext, X, Y, Seed);
		if (Value >= From && Value <= To)
		{
			return FFixed64(1);
		}

		return FFixed64(0);
	}
};

UCLASS(Blueprintable)
class MMTNOISE_API UNoiseModuleResolution : public UNoiseModule
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFixed64 ResolutionMultiplier;

	virtual int GetSourceModuleCount() const override { return 1; }

	virtual FFixed64 GetHeightAt(UObject* WorldContext, int X, int Y, int Seed) override
	{
		int X1 = static_cast<int>(FFixed64::Round(X / ResolutionMultiplier) * ResolutionMultiplier);
		int Y1 = static_cast<int>(FFixed64::Round(Y / ResolutionMultiplier) * ResolutionMultiplier);

		return SourceModules[0]->GetHeightAt(WorldContext, X1, Y1, Seed);
	}
};

UCLASS(Blueprintable)
class MMTNOISE_API UNoiseModuleTurbulence : public UNoiseModule
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFixed64 Power;

	virtual int GetSourceModuleCount() const override { return 3; }

	virtual FFixed64 GetHeightAt(UObject* WorldContext, int X, int Y, int Seed) override
	{
		FFixed64 X0, Y0;
		FFixed64 X1, Y1;

		X0 = X + FFixed64(12414.0 / 65536.0);
		Y0 = Y + FFixed64(65124.0 / 65536.0);
		X1 = X + FFixed64(26519.0 / 65536.0);
		Y1 = Y + FFixed64(18128.0 / 65536.0);

		FFixed64 XDistort = X + (SourceModules[1]->GetHeightAt(WorldContext, static_cast<int>(X0), static_cast<int>(Y0), Seed) * Power);
		FFixed64 YDistort = Y + (SourceModules[2]->GetHeightAt(WorldContext, static_cast<int>(X1), static_cast<int>(Y1), Seed) * Power);

		FFixed64 Value = SourceModules[0]->GetHeightAt(WorldContext, static_cast<int>(XDistort), static_cast<int>(YDistort), Seed);
		return Value;
	}
};
