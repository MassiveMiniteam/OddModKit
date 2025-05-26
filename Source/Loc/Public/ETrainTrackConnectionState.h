#pragma once
#include "CoreMinimal.h"
#include "ETrainTrackConnectionState.generated.h"

UENUM(BlueprintType)
enum class ETrainTrackConnectionState : uint8 {
    Possible,
    Impossible,
    Succcess,
    Fail,
};

