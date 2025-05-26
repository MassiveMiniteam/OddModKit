#pragma once
#include "CoreMinimal.h"
#include "LogoutEventDelegate.generated.h"

class AController;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLogoutEvent, AController*, Controller);

