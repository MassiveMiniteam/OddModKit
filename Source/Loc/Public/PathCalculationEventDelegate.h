#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PathCalculationEventDelegate.generated.h"

class UPathCalculatationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPathCalculationEvent, UPathCalculatationComponent*, Component, TArray<FIntVector>, Path);

