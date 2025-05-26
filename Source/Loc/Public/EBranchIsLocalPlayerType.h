#pragma once
#include "CoreMinimal.h"
#include "EBranchIsLocalPlayerType.generated.h"

UENUM(BlueprintType)
enum class EBranchIsLocalPlayerType : uint8 {
    IsLocalPlayer,
    NotLocalPlayer,
};

