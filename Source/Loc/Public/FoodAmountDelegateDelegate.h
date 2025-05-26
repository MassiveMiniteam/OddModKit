#pragma once
#include "CoreMinimal.h"
#include "FoodAmountDelegateDelegate.generated.h"

class UFoodSourceComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFoodAmountDelegate, UFoodSourceComponent*, FoodSourceComponent, int32, Amount);

