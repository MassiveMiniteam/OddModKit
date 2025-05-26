#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OnUserScrolledVectorEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUserScrolledVectorEvent, FVector2D, CurrentOffset);

