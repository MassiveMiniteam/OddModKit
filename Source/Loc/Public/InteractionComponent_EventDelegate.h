#pragma once
#include "CoreMinimal.h"
#include "InteractionComponent_EventDelegate.generated.h"

class UInteractionPresentationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FInteractionComponent_Event, UInteractionPresentationComponent*, Component);

