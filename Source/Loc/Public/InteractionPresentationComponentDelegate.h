#pragma once
#include "CoreMinimal.h"
#include "InteractionPresentationComponentDelegate.generated.h"

class UInteractionPresentationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInteractionPresentationComponent, UInteractionPresentationComponent*, Component);

