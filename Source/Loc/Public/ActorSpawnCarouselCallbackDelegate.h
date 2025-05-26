#pragma once
#include "CoreMinimal.h"
#include "ActorSpawnCarouselCallbackDelegate.generated.h"

class ASimulationActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FActorSpawnCarouselCallback, ASimulationActor*, Actor);

