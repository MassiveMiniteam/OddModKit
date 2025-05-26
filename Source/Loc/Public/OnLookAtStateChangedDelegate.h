#pragma once
#include "CoreMinimal.h"
#include "OnLookAtStateChangedDelegate.generated.h"

class UInteractionPresentationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLookAtStateChanged, UInteractionPresentationComponent*, Component, bool, bLookAtState);

