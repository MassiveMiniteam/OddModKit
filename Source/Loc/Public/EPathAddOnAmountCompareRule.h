#pragma once
#include "CoreMinimal.h"
#include "EPathAddOnAmountCompareRule.generated.h"

UENUM(BlueprintType)
enum class EPathAddOnAmountCompareRule : uint8 {
    Equal,
    EqualOrMore,
    EqualOrLess,
};

