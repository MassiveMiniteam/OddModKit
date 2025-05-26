#pragma once
#include "CoreMinimal.h"
#include "ETrainBuildingResult.generated.h"

UENUM(BlueprintType)
enum class ETrainBuildingResult : uint8 {
    Fail_InvalidTracks,
    Fail_NotEnoughResources,
    Fail_BlockedLocation,
    Success,
};

