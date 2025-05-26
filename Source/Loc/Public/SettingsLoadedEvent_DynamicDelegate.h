#pragma once
#include "CoreMinimal.h"
#include "SettingsLoadedEvent_DynamicDelegate.generated.h"

class ULocGlobalSettingsSave;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSettingsLoadedEvent_Dynamic, ULocGlobalSettingsSave*, Settings);

