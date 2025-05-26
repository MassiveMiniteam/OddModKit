#pragma once
#include "CoreMinimal.h"
#include "MMTCloudSavegamesFoundEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FMMTCloudSavegamesFoundEvent, const TArray<FString>&, FileNames);

