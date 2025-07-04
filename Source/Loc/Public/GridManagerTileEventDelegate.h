#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GridManagerTileEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGridManagerTileEvent, TArray<FIntPoint>, Tiles);

