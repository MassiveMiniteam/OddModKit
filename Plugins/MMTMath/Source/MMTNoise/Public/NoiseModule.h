#pragma once

#include "CoreMinimal.h"
#include "Fixed64.h"
#include "NoiseModule.generated.h"

UCLASS(Blueprintable)
class MMTNOISE_API UNoiseModule : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<UNoiseModule*> SourceModules;

	virtual bool HasCorrectSourceModules()
	{
		if (SourceModules.Num() != GetSourceModuleCount())
		{
			return false;
		}

		for (int i = 0; i < GetSourceModuleCount(); i++)
		{
			if (SourceModules[i] == nullptr)
			{
				return false;
			}
		}
		return true;
	}

	virtual int GetSourceModuleCount() const { return 0; };

	virtual FFixed64 GetHeightAt(UObject* WorldContext, int X, int Y, int Seed)
	{
		return 0;
	}
};
