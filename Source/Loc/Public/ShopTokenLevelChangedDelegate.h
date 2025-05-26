#pragma once
#include "CoreMinimal.h"
#include "ShopTokenLevelChangedDelegate.generated.h"

class UShopTokenGeneratorComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FShopTokenLevelChanged, UShopTokenGeneratorComponent*, ShopTokenGenerator, int32, CurrentLevel);

