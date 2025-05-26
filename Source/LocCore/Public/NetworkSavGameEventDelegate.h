#pragma once
#include "CoreMinimal.h"
#include "NetworkSavGameEventDelegate.generated.h"

class ULocCoreSaveGame;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNetworkSavGameEvent, ULocCoreSaveGame*, SaveGame);

