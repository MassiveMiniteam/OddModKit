#pragma once
#include "CoreMinimal.h"
#include "ETrainStopStationMode.generated.h"

UENUM(BlueprintType)
enum class ETrainStopStationMode : uint8 {
    Timer,
    Loader,
    Unloader,
};

