#pragma once
#include "CoreMinimal.h"
#include "DialogueSlideConfig.h"
#include "DialoguePlayer_SlideConfig_EventDelegate.generated.h"

class UDialoguePlayerComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDialoguePlayer_SlideConfig_Event, UDialoguePlayerComponent*, DialoguePlayer, FDialogueSlideConfig, DialogSlide);

