#pragma once
#include "CoreMinimal.h"
#include "OnTabIndexSelectedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTabIndexSelected, int32, NewIndex);

