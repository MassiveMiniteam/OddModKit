#pragma once
#include "CoreMinimal.h"
#include "OnTabButtonClickedDelegate.generated.h"

class UTabButton;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTabButtonClicked, UTabButton*, Button, int32, NewIndex);

