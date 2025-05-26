#pragma once
#include "CoreMinimal.h"
#include "ECraftingStatusCode.generated.h"

UENUM(BlueprintType)
enum class ECraftingStatusCode : uint8 {
    Processing,
    Error_NoResources,
    Error_NoRecipe,
    Error_NoWorkers,
};

