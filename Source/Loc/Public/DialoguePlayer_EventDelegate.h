#pragma once
#include "CoreMinimal.h"
#include "DialoguePlayer_EventDelegate.generated.h"

class UDialogueConfig;
class UDialoguePlayerComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDialoguePlayer_Event, UDialoguePlayerComponent*, DialoguePlayer, UDialogueConfig*, Dialogue);

