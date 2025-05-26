#pragma once
#include "CoreMinimal.h"
#include "EEntitlementState.generated.h"

UENUM(BlueprintType)
enum class EEntitlementState : uint8 {
    Querying,
    Queried,
    UpdateRequested,
};

