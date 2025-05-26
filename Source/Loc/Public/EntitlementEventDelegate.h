#pragma once
#include "CoreMinimal.h"
#include "EntitlementEventDelegate.generated.h"

class UProductEntitlementDataAsset;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEntitlementEvent, UProductEntitlementDataAsset*, Asset);

