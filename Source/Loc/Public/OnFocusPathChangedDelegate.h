#pragma once
#include "CoreMinimal.h"
#include "OnFocusPathChangedDelegate.generated.h"

class UNavFocusPath;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFocusPathChanged, UNavFocusPath*, Path);

