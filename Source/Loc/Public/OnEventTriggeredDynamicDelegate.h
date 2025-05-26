#pragma once
#include "CoreMinimal.h"
#include "OnEventTriggeredDynamicDelegate.generated.h"

class UEventDataAsset;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FOnEventTriggeredDynamic, UEventDataAsset*, EventDataAsset);

