#pragma once
#include "CoreMinimal.h"
#include "AsyncEventDelegate.generated.h"

class UObject;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_TwoParams(FAsyncEvent, UObject*, LoadedObject, UObject*, customData);

