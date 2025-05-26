#pragma once
#include "CoreMinimal.h"
#include "OnActorAddedDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorAdded, const AActor*, Actor);

