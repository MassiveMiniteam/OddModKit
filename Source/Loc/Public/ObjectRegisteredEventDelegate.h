#pragma once
#include "CoreMinimal.h"
#include "ObjectRegisteredEventDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FObjectRegisteredEvent, AActor*, Actor);

