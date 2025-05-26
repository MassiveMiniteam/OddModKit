#pragma once
#include "CoreMinimal.h"
#include "SubGridMovementIsAboutToEnterNewTileDelegateDelegate.generated.h"

class USubGridMovementSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSubGridMovementIsAboutToEnterNewTileDelegate, USubGridMovementSimulationComponent*, Component);

