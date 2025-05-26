#pragma once
#include "CoreMinimal.h"
#include "SpawnPinnedObjectMarkerEventDelegate.generated.h"

class ASimulationActor;
class UInteractFromWorldmapCommand;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_TwoParams(FSpawnPinnedObjectMarkerEvent, UInteractFromWorldmapCommand*, Command, ASimulationActor*, SpawnedActor);

