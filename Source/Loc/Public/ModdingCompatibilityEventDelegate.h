#pragma once
#include "CoreMinimal.h"
#include "ESaveGameCompatibilityError.h"
#include "ModdingCompatibilityEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_TwoParams(FModdingCompatibilityEvent, ESaveGameCompatibilityError, Result, const FString&, Error);

