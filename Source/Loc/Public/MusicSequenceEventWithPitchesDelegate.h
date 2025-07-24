#pragma once
#include "CoreMinimal.h"
#include "MusicPitch.h"
#include "MusicSequenceEventWithPitchesDelegate.generated.h"

class UMusicSequencePlayerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMusicSequenceEventWithPitches, UMusicSequencePlayerSimulationComponent*, Player, const TArray<FMusicPitch>&, ScheduledPitches);

