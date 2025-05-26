#pragma once
#include "CoreMinimal.h"
#include "OnPolePositionOffsetChanged_DelegateDelegate.generated.h"

class UTrainTracksPoleBaseSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPolePositionOffsetChanged_Delegate, UTrainTracksPoleBaseSimulationComponent*, Pole);

