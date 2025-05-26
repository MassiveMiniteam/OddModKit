#pragma once
#include "CoreMinimal.h"
#include "EMapIconInteractionType.h"
#include "MapIconWidget_EventDelegate.generated.h"

class UMapIconWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMapIconWidget_Event, UMapIconWidget*, MapIconWidget, EMapIconInteractionType, InteractionType);

