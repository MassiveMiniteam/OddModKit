#pragma once
#include "CoreMinimal.h"
#include "ECopyToolPasteOrder.generated.h"

UENUM(BlueprintType)
enum class ECopyToolPasteOrder : uint8 {
    Early,
    Late,
};

