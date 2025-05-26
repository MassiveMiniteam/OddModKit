#pragma once
#include "CoreMinimal.h"
#include "OnTrainStartedMovement_DelegateDelegate.generated.h"

class UTrainTracksAgentSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTrainStartedMovement_Delegate, UTrainTracksAgentSimulationComponent*, Agent);

