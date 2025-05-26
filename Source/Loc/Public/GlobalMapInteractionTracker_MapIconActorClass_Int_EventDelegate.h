#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GlobalMapInteractionTracker_MapIconActorClass_Int_EventDelegate.generated.h"

class ASimulationActor;
class UGlobalMapInteractionTracker;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FGlobalMapInteractionTracker_MapIconActorClass_Int_Event, UGlobalMapInteractionTracker*, Tracker, TSubclassOf<ASimulationActor>, MapIconActorClass, int32, Value);

