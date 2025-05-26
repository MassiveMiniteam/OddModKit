#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "GlobalStatsTrackerEvent_TemperatureOnReceiverChangedDelegate.generated.h"

class UTemperatureReceiverSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGlobalStatsTrackerEvent_TemperatureOnReceiverChanged, UTemperatureReceiverSimulationComponent*, Component, FFixed, NewTemperature);

