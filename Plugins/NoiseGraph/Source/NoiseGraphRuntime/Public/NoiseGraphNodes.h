#pragma once

#include "CoreMinimal.h"
#include "NoiseModule.h"
#include "NoiseGraphNodeNoiseBase.h"
#include "Templates/SubclassOf.h"
#include "NoiseGraphNode.h"
#include "NoiseModuleSimplex.h"
#include "NoiseModules.h"
#include "MMTFixed64/Public/Fixed64.h"
#include "Widgets/SWidget.h"
#include "Widgets/Text/STextBlock.h"
#include "NoiseGraphNodes.generated.h"

UCLASS(Blueprintable)
class NOISEGRAPHRUNTIME_API UNoiseGraphNodeAdd : public UNoiseGraphNodeNoiseBase
{
	GENERATED_BODY()

	virtual TArray<FString> GetInputs() const override
	{
		return { TEXT("A"), TEXT("B") };
	}

	virtual TSubclassOf<UNoiseModule> GetNoiseModuleClass() const override
	{
		return UNoiseModuleAdd::StaticClass();
	}
};

UCLASS(Blueprintable)
class NOISEGRAPHRUNTIME_API UNoiseGraphNodeSubtract : public UNoiseGraphNodeNoiseBase
{
	GENERATED_BODY()

	virtual TArray<FString> GetInputs() const override
	{
		return { TEXT("A"), TEXT("B") };
	}

	virtual TSubclassOf<UNoiseModule> GetNoiseModuleClass() const override
	{
		return UNoiseModuleSubtract::StaticClass();
	}
};

UCLASS(Blueprintable)
class NOISEGRAPHRUNTIME_API UNoiseGraphNodeMultiply : public UNoiseGraphNodeNoiseBase
{
	GENERATED_BODY()

	virtual TArray<FString> GetInputs() const override
	{
		return { TEXT("A"), TEXT("B") };
	}

	virtual TSubclassOf<UNoiseModule> GetNoiseModuleClass() const override
	{
		return UNoiseModuleMultiply::StaticClass();
	}
};

UCLASS(Blueprintable)
class NOISEGRAPHRUNTIME_API UNoiseGraphNodeMin : public UNoiseGraphNodeNoiseBase
{
	GENERATED_BODY()

	virtual TArray<FString> GetInputs() const override
	{
		return { TEXT("A"), TEXT("B") };
	}

	virtual TSubclassOf<UNoiseModule> GetNoiseModuleClass() const override
	{
		return UNoiseModuleMin::StaticClass();
	}
};

UCLASS(Blueprintable)
class NOISEGRAPHRUNTIME_API UNoiseGraphNodeMax : public UNoiseGraphNodeNoiseBase
{
	GENERATED_BODY()

	virtual TArray<FString> GetInputs() const override
	{
		return { TEXT("A"), TEXT("B") };
	}

	virtual TSubclassOf<UNoiseModule> GetNoiseModuleClass() const override
	{
		return UNoiseModuleMax::StaticClass();
	}
};

UCLASS(Blueprintable)
class NOISEGRAPHRUNTIME_API UNoiseGraphNodeAbs : public UNoiseGraphNodeNoiseBase
{
	GENERATED_BODY()

	virtual TArray<FString> GetInputs() const override
	{
		return { TEXT("A") };
	}

	virtual TSubclassOf<UNoiseModule> GetNoiseModuleClass() const override
	{
		return UNoiseModuleAbs::StaticClass();
	}
};

UCLASS(Blueprintable)
class NOISEGRAPHRUNTIME_API UNoiseGraphNodeConst : public UNoiseGraphNodeNoiseBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FFixed64 Const;
	
	virtual UNoiseModule* GetNoiseModule(int32 InSeed) override
	{
		UNoiseModuleConst* Noise = Cast<UNoiseModuleConst>(Super::GetNoiseModule(InSeed));
		Noise->Const = Const;
		return Noise;
	}

	virtual bool GetShouldRenderPreview() const override
	{
		return false;
	}
	
	virtual TSubclassOf<UNoiseModule> GetNoiseModuleClass() const override
	{
		return UNoiseModuleConst::StaticClass();
	}

	virtual TSharedRef<SWidget> AddCustomSlateToNode() override
	{
		return SNew(STextBlock)
		.Text(FText::FromString(FString::Printf(TEXT("Const: %f"), static_cast<float>(Const))));
	}

#if WITH_EDITOR
	virtual FText GetNodeTitle() const override
	{
		return FText::FromString(FString::Printf(TEXT("%f"), static_cast<float>(Const)));
	}
#endif
};

UCLASS(Blueprintable)
class NOISEGRAPHRUNTIME_API UNoiseGraphNodeClamp : public UNoiseGraphNodeNoiseBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FFixed64 Min;
	
	UPROPERTY(EditAnywhere)
	FFixed64 Max;
	
	virtual TArray<FString> GetInputs() const override
	{
		return { TEXT("A") };
	}
	
	virtual UNoiseModule* GetNoiseModule(int32 InSeed) override
	{
		UNoiseModuleClamp* Noise = Cast<UNoiseModuleClamp>(Super::GetNoiseModule(InSeed));
		if (Noise != nullptr)
		{
			Noise->Min = Min;
			Noise->Max = Max;
		}
		return Noise;
	}

	virtual TSubclassOf<UNoiseModule> GetNoiseModuleClass() const override
	{
		return UNoiseModuleClamp::StaticClass();
	}
};

UCLASS(Blueprintable)
class NOISEGRAPHRUNTIME_API UNoiseGraphNodePower : public UNoiseGraphNodeNoiseBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	int Power;
	
	virtual TArray<FString> GetInputs() const override
	{
		return { TEXT("A") };
	}
	
	virtual UNoiseModule* GetNoiseModule(int32 InSeed) override
	{
		UNoiseModulePower* Noise = Cast<UNoiseModulePower>(Super::GetNoiseModule(InSeed));
		if (Noise != nullptr)
		{
			Noise->Power = Power;
		}
		return Noise;
	}

	virtual TSubclassOf<UNoiseModule> GetNoiseModuleClass() const override
	{
		return UNoiseModulePower::StaticClass();
	}
};

UCLASS(Blueprintable)
class NOISEGRAPHRUNTIME_API UNoiseGraphNodeRemap : public UNoiseGraphNodeNoiseBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FFixed64 FromLow;
	UPROPERTY(EditAnywhere)
	FFixed64 FromHigh;
	
	UPROPERTY(EditAnywhere)
	FFixed64 ToLow;
	UPROPERTY(EditAnywhere)
	FFixed64 ToHigh;
	
	virtual TArray<FString> GetInputs() const override
	{
		return { TEXT("A") };
	}
	
	virtual UNoiseModule* GetNoiseModule(int32 InSeed) override
	{
		UNoiseModuleRemap* Noise = Cast<UNoiseModuleRemap>(Super::GetNoiseModule(InSeed));
		if (Noise != nullptr)
		{
			Noise->FromLow = FromLow;
			Noise->FromHigh = FromHigh;
			Noise->ToLow = ToLow;
			Noise->ToHigh = ToHigh;
		}
		return Noise;
	}

	virtual TSubclassOf<UNoiseModule> GetNoiseModuleClass() const override
	{
		return UNoiseModuleRemap::StaticClass();
	}
};

UCLASS(Blueprintable)
class NOISEGRAPHRUNTIME_API UNoiseGraphNodeMask : public UNoiseGraphNodeNoiseBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FFixed64 From;
	UPROPERTY(EditAnywhere)
	FFixed64 To;
	
	virtual TArray<FString> GetInputs() const override
	{
		return { TEXT("A") };
	}
	
	virtual UNoiseModule* GetNoiseModule(int32 InSeed) override
	{
		UNoiseModuleMask* Noise = Cast<UNoiseModuleMask>(Super::GetNoiseModule(InSeed));
		if (Noise != nullptr)
		{
			Noise->From = From;
			Noise->To = To;
		}
		return Noise;
	}

	virtual TSubclassOf<UNoiseModule> GetNoiseModuleClass() const override
	{
		return UNoiseModuleMask::StaticClass();
	}
};

UCLASS(Blueprintable)
class NOISEGRAPHRUNTIME_API UNoiseGraphNodeResolution : public UNoiseGraphNodeNoiseBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FFixed64 ResolutionMultiplier;
	
	virtual TArray<FString> GetInputs() const override
	{
		return { TEXT("A") };
	}
	
	virtual UNoiseModule* GetNoiseModule(int32 InSeed) override
	{
		UNoiseModuleResolution* Noise = Cast<UNoiseModuleResolution>(Super::GetNoiseModule(InSeed));
		if (Noise != nullptr)
		{
			Noise->ResolutionMultiplier = ResolutionMultiplier;
		}
		return Noise;
	}

	virtual TSubclassOf<UNoiseModule> GetNoiseModuleClass() const override
	{
		return UNoiseModuleResolution::StaticClass();
	}
};

UCLASS(Blueprintable)
class NOISEGRAPHRUNTIME_API UNoiseGraphNodeTurbulence : public UNoiseGraphNodeNoiseBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FFixed64 Power;
	
	virtual TArray<FString> GetInputs() const override
	{
		return { TEXT("A"), TEXT("X"), TEXT("Y") };
	}
	
	virtual UNoiseModule* GetNoiseModule(int32 InSeed) override
	{
		UNoiseModuleTurbulence* Noise = Cast<UNoiseModuleTurbulence>(Super::GetNoiseModule(InSeed));
		if (Noise != nullptr)
		{
			Noise->Power = Power;
		}
		return Noise;
	}

	virtual TSubclassOf<UNoiseModule> GetNoiseModuleClass() const override
	{
		return UNoiseModuleTurbulence::StaticClass();
	}
};
