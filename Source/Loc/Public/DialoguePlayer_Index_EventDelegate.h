#pragma once
#include "CoreMinimal.h"
#include "DialoguePlayer_Index_EventDelegate.generated.h"

class UDialoguePlayerComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDialoguePlayer_Index_Event, UDialoguePlayerComponent*, DialoguePlayer, int32, Index);

