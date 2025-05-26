#pragma once
#include "CoreMinimal.h"
#include "OnTabIndexChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTabIndexChanged, int32, NewIndex);

