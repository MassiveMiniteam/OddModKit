#pragma once
#include "CoreMinimal.h"
#include "ERecipeOutputBehaviour.generated.h"

UENUM(BlueprintType)
enum class ERecipeOutputBehaviour : uint8 {
    All,
    Random,
    WeightedRandom,
};

