#pragma once
#include "CoreMinimal.h"
#include "EConstructionSiteState.generated.h"

UENUM(BlueprintType)
enum class EConstructionSiteState : uint8 {
    Reserved,
    UnderConstruction,
    Finished,
    DebugShowAll,
};

