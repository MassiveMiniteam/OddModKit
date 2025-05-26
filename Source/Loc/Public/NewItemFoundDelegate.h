#pragma once
#include "CoreMinimal.h"
#include "NewItemFoundDelegate.generated.h"

class UItemConfig;
class UResourcesCounterSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNewItemFound, UResourcesCounterSimulationComponent*, Component, UItemConfig*, Item);

