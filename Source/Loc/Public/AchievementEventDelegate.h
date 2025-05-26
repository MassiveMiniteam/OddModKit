#pragma once
#include "CoreMinimal.h"
#include "AchievementEventDelegate.generated.h"

class UAchievement;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAchievementEvent, UAchievement*, Achievement);

