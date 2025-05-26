#pragma once
#include "CoreMinimal.h"
#include "GameplayEffectTriggerDelegate.generated.h"

class AGameplayEffectEmitter;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameplayEffectTrigger, AGameplayEffectEmitter*, Emitter);

