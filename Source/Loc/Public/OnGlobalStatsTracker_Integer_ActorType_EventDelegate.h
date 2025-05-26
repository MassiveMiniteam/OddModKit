#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OnGlobalStatsTracker_Integer_ActorType_EventDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGlobalStatsTracker_Integer_ActorType_Event, TSubclassOf<AActor>, ActorType, int32, Value);

