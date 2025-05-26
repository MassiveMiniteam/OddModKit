#pragma once
#include "CoreMinimal.h"
#include "OnNoteIndexChangedDelegate.generated.h"

class UPathAddOn_PlayMusicNote_SimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNoteIndexChanged, UPathAddOn_PlayMusicNote_SimulationComponent*, Component, int32, NoteIndex);

