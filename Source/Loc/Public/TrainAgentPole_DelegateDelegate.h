#pragma once
#include "CoreMinimal.h"
#include "TrainAgentPole_DelegateDelegate.generated.h"

class UTrainTracksAgentSimulationComponent;
class UTrainTracksPoleBaseSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTrainAgentPole_Delegate, const UTrainTracksPoleBaseSimulationComponent*, Pole, const UTrainTracksAgentSimulationComponent*, Agent);

