#pragma once
#include "CoreMinimal.h"
#include "WorldGeneratorProfilerDelegateDelegate.generated.h"

class UWorldGenerator;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FWorldGeneratorProfilerDelegate, UWorldGenerator*, WorldGenerator, const FString&, StepName, float, DurationFromStart);

