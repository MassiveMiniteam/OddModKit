#pragma once
#include "CoreMinimal.h"
#include "BallonEventDelegate.generated.h"

class UBalloonCarrySimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBallonEvent, UBalloonCarrySimulationComponent*, Component);

