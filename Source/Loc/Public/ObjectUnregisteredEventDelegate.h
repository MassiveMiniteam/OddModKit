#pragma once
#include "CoreMinimal.h"
#include "ObjectUnregisteredEventDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FObjectUnregisteredEvent, AActor*, Actor);

