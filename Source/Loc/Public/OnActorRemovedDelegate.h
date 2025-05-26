#pragma once
#include "CoreMinimal.h"
#include "OnActorRemovedDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorRemoved, const AActor*, Actor);

