#pragma once
#include "CoreMinimal.h"
#include "SaveGameLoadedEventDelegate.generated.h"

class ULocMetaSaveGame;
class ULocSaveGame;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_FourParams(FSaveGameLoadedEvent, bool, bSuccess, const FString&, Name, ULocMetaSaveGame*, Meta, ULocSaveGame*, SaveGame);

