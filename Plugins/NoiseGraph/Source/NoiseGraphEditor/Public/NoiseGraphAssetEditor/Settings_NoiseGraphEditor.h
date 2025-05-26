#pragma once

#include "CoreMinimal.h"
#include "Settings_NoiseGraphEditor.generated.h"

UENUM(BlueprintType)
enum class EAutoLayoutStrategy : uint8
{
	Tree,
	ForceDirected,
};

UCLASS()
class NOISEGRAPHEDITOR_API UNoiseGraphEditorSettings : public UObject
{
	GENERATED_BODY()

public:
	UNoiseGraphEditorSettings();
	virtual ~UNoiseGraphEditorSettings();

	UPROPERTY(EditDefaultsOnly, Category = "AutoArrange")
	float OptimalDistance;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category = "AutoArrange")
	EAutoLayoutStrategy AutoLayoutStrategy;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category = "AutoArrange")
	int32 MaxIteration;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category = "AutoArrange")
	bool bFirstPassOnly;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category = "AutoArrange")
	bool bRandomInit;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category = "AutoArrange")
	float InitTemperature;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category = "AutoArrange")
	float CoolDownRate;
};
