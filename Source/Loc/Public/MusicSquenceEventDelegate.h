#pragma once
#include "CoreMinimal.h"
#include "MusicSquenceEventDelegate.generated.h"

class UMusicSequencePlayerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMusicSquenceEvent, UMusicSequencePlayerSimulationComponent*, Player);

