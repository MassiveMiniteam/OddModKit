#pragma once
#include "CoreMinimal.h"
#include "ELifeTimeEndEvent.generated.h"

UENUM(BlueprintType)
enum class ELifeTimeEndEvent : uint8 {
    MarkAsDeath,
    Despawn,
};

