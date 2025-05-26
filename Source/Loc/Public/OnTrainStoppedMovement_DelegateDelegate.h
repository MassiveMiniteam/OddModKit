#pragma once
#include "CoreMinimal.h"
#include "OnTrainStoppedMovement_DelegateDelegate.generated.h"

class UTrainTracksAgentSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTrainStoppedMovement_Delegate, UTrainTracksAgentSimulationComponent*, Agent);

