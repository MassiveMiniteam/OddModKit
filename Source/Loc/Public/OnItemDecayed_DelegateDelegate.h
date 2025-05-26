#pragma once
#include "CoreMinimal.h"
#include "OnItemDecayed_DelegateDelegate.generated.h"

class UItemConfig;
class UItemDecayComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemDecayed_Delegate, UItemDecayComponent*, Component, UItemConfig*, ItemConfig);

