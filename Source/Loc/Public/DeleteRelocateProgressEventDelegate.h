#pragma once
#include "CoreMinimal.h"
#include "DeleteRelocateProgressEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDeleteRelocateProgressEvent, float, Progress);

