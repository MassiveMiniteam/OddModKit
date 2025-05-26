#pragma once
#include "CoreMinimal.h"
#include "OnPlayerReportCompletedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FOnPlayerReportCompleted, bool, bSuccess);

