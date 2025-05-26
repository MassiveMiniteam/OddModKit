#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GlobalAITrackerEvent_Actor_StateDelegate.generated.h"

class AActor;
class UBaseState;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGlobalAITrackerEvent_Actor_State, TSubclassOf<AActor>, ActorType, TSubclassOf<UBaseState>, StateClass);

