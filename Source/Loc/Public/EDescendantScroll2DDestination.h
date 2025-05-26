#pragma once
#include "CoreMinimal.h"
#include "EDescendantScroll2DDestination.generated.h"

UENUM(BlueprintType)
enum class EDescendantScroll2DDestination : uint8 {
    IntoView,
    TopOrLeft,
    Center,
    BottomOrRight,
};

