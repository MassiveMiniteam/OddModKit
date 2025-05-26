#pragma once
#include "CoreMinimal.h"
#include "OnNewItemConfigTrackedDelegateDelegate.generated.h"

class UItemConfig;
class URecipeTrackerSubsystem;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNewItemConfigTrackedDelegate, URecipeTrackerSubsystem*, RecipeTrackerSubsystem, UItemConfig*, ItemConfig);

