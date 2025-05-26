#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HostilityTileEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHostilityTileEvent, FIntPoint, GridPosition, int32, NewHostility);

