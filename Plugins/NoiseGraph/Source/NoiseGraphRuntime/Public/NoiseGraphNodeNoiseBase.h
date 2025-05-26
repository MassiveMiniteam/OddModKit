#pragma once

#include "CoreMinimal.h"
#include "NoiseGraphNode.h"
#include "NoiseGraphNodeNoiseBase.generated.h"

UCLASS(Blueprintable, Abstract)
class NOISEGRAPHRUNTIME_API UNoiseGraphNodeNoiseBase : public UNoiseGraphNode
{
	GENERATED_BODY()

protected:
	virtual TSubclassOf<UNoiseModule> GetNoiseModuleClass() const
	{
		return UNoiseModule::StaticClass();
	}

#if WITH_EDITOR
	virtual FText GetNodeTitle() const override
	{
		FString Text = Cast<UNoiseModule>(GetNoiseModuleClass()->GetDefaultObject())->GetName();
		Text = Text.Replace(TEXT("Default__"), TEXT(""));
		Text = Text.Replace(TEXT("NoiseModule"), TEXT(""));
		return FText::FromString(Text);
	}
#endif
	
	virtual UNoiseModule* GetNoiseModule(int32 InSeed) override
	{
		UNoiseModule* Noise = NewObject<UNoiseModule>(this, GetNoiseModuleClass());

		for (int i = 0; i < Noise->GetSourceModuleCount(); i++)
		{
			if (Edges.Num() > i)
			{
				Noise->SourceModules.Add(GetNoiseAt(i, InSeed));
			}
		}

		if (!Noise->HasCorrectSourceModules())
		{
			return nullptr;
		}
		return Noise;
	}
};

