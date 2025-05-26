#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "NoiseGraph.h"
#include "NoiseGraphFactory.generated.h"

UCLASS()
class NOISEGRAPHEDITOR_API UNoiseGraphFactory : public UFactory
{
	GENERATED_BODY()

public:
	UNoiseGraphFactory();
	virtual ~UNoiseGraphFactory();

	UPROPERTY(EditAnywhere, Category=DataAsset)
	TSubclassOf<UNoiseGraph> NoiseGraphClass;

	virtual bool ConfigureProperties() override;
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
