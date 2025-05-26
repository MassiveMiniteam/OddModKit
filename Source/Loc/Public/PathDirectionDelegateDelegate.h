#pragma once
#include "CoreMinimal.h"
#include "PathDirectionDelegateDelegate.generated.h"

class UPathAddOn_ThreeWaySplit_SimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPathDirectionDelegate, UPathAddOn_ThreeWaySplit_SimulationComponent*, PathAddOn_ThreeWaySplit_SimulationComponent);

