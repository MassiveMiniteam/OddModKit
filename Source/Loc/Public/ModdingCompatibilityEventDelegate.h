#pragma once
#include "CoreMinimal.h"
#include "ModdingCompatibilityEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_TwoParams(FModdingCompatibilityEvent, bool, bSuccess, const FString&, Error);

