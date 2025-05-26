#pragma once
#include "CoreMinimal.h"
#include "ETerraformHeightType.generated.h"

UENUM(BlueprintType)
enum class ETerraformHeightType : uint8 {
    CenterPlusOne,
    CenterMinusOne,
    CurrentPlusOne,
    Nothing,
};

