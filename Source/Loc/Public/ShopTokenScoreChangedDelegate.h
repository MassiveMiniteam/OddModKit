#pragma once
#include "CoreMinimal.h"
#include "ShopTokenScoreChangedDelegate.generated.h"

class UShopTokenGeneratorComponent;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FShopTokenScoreChanged, UShopTokenGeneratorComponent*, ShopTokenGenerator, int64, CurrentScore);

