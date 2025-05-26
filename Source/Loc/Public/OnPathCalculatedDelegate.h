#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EPathFindingRequestResult.h"
#include "OnPathCalculatedDelegate.generated.h"

class UPathFinderComponent;
class UPathFindingRequest;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnPathCalculated, UPathFinderComponent*, PathFinderComponent, EPathFindingRequestResult, Result, UPathFindingRequest*, Path, FIntVector, TargetPosition);

