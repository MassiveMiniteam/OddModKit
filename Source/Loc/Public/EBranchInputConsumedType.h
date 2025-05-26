#pragma once
#include "CoreMinimal.h"
#include "EBranchInputConsumedType.generated.h"

UENUM(BlueprintType)
enum class EBranchInputConsumedType : uint8 {
    Consumed,
    NotConsumed,
};

