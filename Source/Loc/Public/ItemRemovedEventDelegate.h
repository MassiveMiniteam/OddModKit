#pragma once
#include "CoreMinimal.h"
#include "ItemRemovedEventDelegate.generated.h"

class UItemConfig;
class UObject;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FItemRemovedEvent, UItemConfig*, Config, int32, Amount, UObject*, Origin);

