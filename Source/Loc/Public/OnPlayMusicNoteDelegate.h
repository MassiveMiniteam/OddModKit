#pragma once
#include "CoreMinimal.h"
#include "OnPlayMusicNoteDelegate.generated.h"

class UItemMinionConfig;
class UPathAddOn_PlayMusicNote_SimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlayMusicNote, UPathAddOn_PlayMusicNote_SimulationComponent*, PlayMusicNoteComponent, int32, NoteIndex, UItemMinionConfig*, MinionConfig);

