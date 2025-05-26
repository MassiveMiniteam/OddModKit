#pragma once
#include "CoreMinimal.h"
#include "OnPoleConnectionsChanged_DelegateDelegate.generated.h"

class UTrainTracksPoleBaseSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPoleConnectionsChanged_Delegate, UTrainTracksPoleBaseSimulationComponent*, Pole);

