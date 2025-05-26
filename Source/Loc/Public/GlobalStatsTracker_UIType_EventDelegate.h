#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GlobalStatsTracker_UIType_EventDelegate.generated.h"

class UNavUserWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGlobalStatsTracker_UIType_Event, TSubclassOf<UNavUserWidget>, WidgetType);

