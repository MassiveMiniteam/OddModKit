#pragma once
#include "CoreMinimal.h"
#include "ItemAddedEventDelegate.generated.h"

class UItemConfig;
class UObject;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FItemAddedEvent, UItemConfig*, Config, int32, Amount, UObject*, Origin);

