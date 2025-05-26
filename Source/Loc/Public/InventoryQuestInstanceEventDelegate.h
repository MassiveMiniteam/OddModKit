#pragma once
#include "CoreMinimal.h"
#include "InventoryQuestInstanceEventDelegate.generated.h"

class AInventoryQuestInstance;
class UInventoryComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInventoryQuestInstanceEvent, AInventoryQuestInstance*, InventoryQuestInstance, UInventoryComponent*, Inventory);

