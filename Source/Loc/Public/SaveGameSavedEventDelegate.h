#pragma once
#include "CoreMinimal.h"
#include "SaveGameSavedEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FSaveGameSavedEvent, bool, bSuccess);

