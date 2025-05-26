#pragma once
#include "CoreMinimal.h"
#include "DialogueBoxWidget_EventDelegate.generated.h"

class UDialogueBoxNavUserWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDialogueBoxWidget_Event, UDialogueBoxNavUserWidget*, DialogueBoxWidget);

