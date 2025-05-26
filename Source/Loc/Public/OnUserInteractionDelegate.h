#pragma once
#include "CoreMinimal.h"
#include "OnUserInteractionDelegate.generated.h"

class UUserPopupWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUserInteraction, UUserPopupWidget*, Widget);

