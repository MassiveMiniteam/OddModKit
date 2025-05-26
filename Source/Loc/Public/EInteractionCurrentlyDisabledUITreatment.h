#pragma once
#include "CoreMinimal.h"
#include "EInteractionCurrentlyDisabledUITreatment.generated.h"

UENUM(BlueprintType)
enum class EInteractionCurrentlyDisabledUITreatment : uint8 {
    GreyOut,
    HideCompletely,
};

