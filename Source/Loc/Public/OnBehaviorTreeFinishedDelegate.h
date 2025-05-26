#pragma once
#include "CoreMinimal.h"
#include "OnBehaviorTreeFinishedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBehaviorTreeFinished, bool, bIsLooping);

