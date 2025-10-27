#pragma once
#include "CoreMinimal.h"
#include "BalloonProviderComponentDelegateDelegate.generated.h"

class UBalloonProviderSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBalloonProviderComponentDelegate, UBalloonProviderSimulationComponent*, Component);

