#pragma once
#include "CoreMinimal.h"
#include "EVisibilityState.generated.h"

UENUM(BlueprintType)
enum EVisibilityState {
    Static,
    Volatile,
    Highlighted,
    Relocating,
    Invisible,
    Deleted,
    AboutToBeDeleted,
};

