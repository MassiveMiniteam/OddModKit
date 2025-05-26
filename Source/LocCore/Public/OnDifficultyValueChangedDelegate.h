#pragma once
#include "CoreMinimal.h"
#include "OnDifficultyValueChangedDelegate.generated.h"

class UDifficultySettingsSubsystem;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDifficultyValueChanged, UDifficultySettingsSubsystem*, Subsystem);

