#pragma once
#include "CoreMinimal.h"
#include "OnNewTrackSegmentReached_DelegateDelegate.generated.h"

class UTrainTracksAgentSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNewTrackSegmentReached_Delegate, UTrainTracksAgentSimulationComponent*, Agent);

