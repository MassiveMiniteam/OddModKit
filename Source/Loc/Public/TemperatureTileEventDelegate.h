#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TemperatureTileEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTemperatureTileEvent, FIntPoint, GridPosition, int32, NewTemperature);

