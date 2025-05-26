#pragma once
#include "CoreMinimal.h"
#include "EXBoxEntitlementType.generated.h"

UENUM(BlueprintType)
enum class EXBoxEntitlementType : uint8 {
    Core,
    Durable,
    DurablePackage,
};

