#pragma once
#include "CoreMinimal.h"
#include "OnChangedValueDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChangedValue, int32, Index, FText, Text);

