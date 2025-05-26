#pragma once
#include "CoreMinimal.h"
#include "OnInteractionTimeUpdateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractionTimeUpdate, float, Value);

