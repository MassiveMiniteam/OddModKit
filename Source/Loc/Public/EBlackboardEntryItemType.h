#pragma once
#include "CoreMinimal.h"
#include "EBlackboardEntryItemType.generated.h"

UENUM(BlueprintType)
enum class EBlackboardEntryItemType : uint8 {
    None,
    IntVector,
    Bool,
    Class,
    Enum,
    Int,
    Name,
    Object,
    String,
};

